//
// Created by JoachimWagner on 30.10.2024.
//

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <stack>
#include "visitor/konto_visitor.h"
namespace composite {

    class abstract_bank_node : public std::enable_shared_from_this<abstract_bank_node>{



    public:
        using VISITOR=visitor::konto_visitor;
        using AbstractNodeShared = std::shared_ptr<abstract_bank_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_bank_node>;
        using Children = std::vector<AbstractNodeShared>;
        using Stack = std::stack<AbstractNodeShared>;

        class Iterator {
        public:
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = abstract_bank_node;
            using difference_type = std::ptrdiff_t;
            using pointer = AbstractNodeShared;
            using reference = abstract_bank_node&;

            explicit Iterator(AbstractNodeShared current_node) : current_node_(current_node) {

            }


            auto operator*() const ->abstract_bank_node & {
                return *current_node_;
            }


            auto operator++()-> Iterator& {
                if (find_most_left_child_and_move_iterator_succeeds()) return *this;
                if (find_next_sibling_and_move_iterator_succeeds()) return *this;
                while (find_next_sibling_of_ancestor_and_move_iterator_failes()) {
                    // Empty
                }
                return *this;
            }
            auto operator++(int dummy)->Iterator {
                Iterator old = *this;
                ++(*this);
                return old;
            }

            auto operator--()-> Iterator& {

                if(stack_.size()> 0){
                    auto previous_sibling = current_node_->previous_sibling();
                    if(previous_sibling)
                        current_node_ = previous_sibling;
                    else {
                        current_node_ = stack_.top();
                        stack_.pop();

                    }
                } else {
                    current_node_ = nullptr;
                }
                return *this;
            }
            auto operator--(int dummy)->Iterator {
                Iterator old = *this;
                --(*this);
                return old;
            }


        private:
            AbstractNodeShared current_node_;
            Stack stack_;


            auto find_most_left_child_and_move_iterator_succeeds()-> bool {
                if (current_node_is_leaf()) return false;
                move_to_most_left_child();
                return true;
            }

            auto find_next_sibling_and_move_iterator_succeeds()-> bool {
                if (stack_.empty()) return false;
                return set_next_sibling_succeeds(current_node_);
            }


            auto find_next_sibling_of_ancestor_and_move_iterator_failes()-> bool {
                if (stack_.size() <= 1) return false;

                return !set_next_sibling_succeeds(get_parent());
            }

            auto get_parent() -> AbstractNodeShared {
                auto parent = stack_.top();
                stack_.pop();
                return parent;
            }

            auto set_next_sibling_succeeds(const AbstractNodeShared &node)->bool {
                current_node_ = node->next_sibling(); // Sets current_node to "End" if failes (nullptr)
                return current_node_.get();
            }


            auto move_to_most_left_child()-> void {
                stack_.push(current_node_);
                current_node_ = current_node_->get_children().front();
            }

            [[nodiscard]] auto current_node_is_leaf() const-> bool {
                return current_node_->get_children().empty();
            }

            friend auto operator==(const Iterator &lhs, const Iterator &rhs)-> bool {
                return lhs.current_node_ == rhs.current_node_;
            }

            friend auto operator!=(const Iterator &lhs, const Iterator &rhs)->bool {
                return !(lhs == rhs);
            }

        };

        explicit abstract_bank_node(std::string name = "undef"): name_{name}{}
        abstract_bank_node(const abstract_bank_node&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&) = delete;
        abstract_bank_node(const abstract_bank_node&&) = delete;
        abstract_bank_node& operator = (const abstract_bank_node&&) = delete;
        virtual ~abstract_bank_node() = default;


        virtual void accept(VISITOR &visitor)=0;

        void iterate(VISITOR &visitor) {
            visitor.init();
            for(auto  &item : *this) {
                //visitor.visit(item.get());
                item.accept(visitor);
            }
            visitor.dispose();
        }
        virtual  auto print(std::ostream& os) const  -> void {
            os << std::string{"name: "} << this->get_name();
        }

        friend auto operator<<(std::ostream &os, const abstract_bank_node &node)-> std::ostream & {
            node.print(os);
            return os;
        }

        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeWeak {
            return parent_;
        }

        auto set_parent(const AbstractNodeWeak &parent)->void {
            parent_ = parent;
        }

        virtual  auto get_children()const  -> Children {
            static Children dummy{};
            return dummy;
        }

        virtual void ausgabe() {

            for(auto & item : *this) {
                std::cout << item << std::endl;
            }
        }

        auto begin()-> Iterator
        {
            return Iterator{ shared_from_this() };
        }

        static auto end()-> Iterator
        {
            return Iterator{ nullptr };
        }

    private:
        AbstractNodeWeak parent_;
        std::string name_;
        auto next_sibling() const -> AbstractNodeShared {
            auto siblings = get_parent().lock()->get_children();
            auto position = std::find_if(siblings.begin(), siblings.end(), [this](AbstractNodeShared const &i){return i.get() == this;});
            return ++position != siblings.end() ? *position : nullptr;
        }

        auto previous_sibling() const -> AbstractNodeShared {
            auto siblings = get_parent().lock()->get_children();
            auto position = std::find_if(siblings.begin(), siblings.end(), [this](AbstractNodeShared const &i){return i.get() == this;});
            return position == siblings.begin() ? nullptr: *(--position);
        }


    };

} // composite
