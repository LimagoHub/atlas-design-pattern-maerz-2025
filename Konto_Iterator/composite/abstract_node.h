//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "NodeVisitor.h"
#include "IteratorVisitor.h"


namespace composite {

    constexpr auto DEBUG_PREFIX = "-----------------------------> DEBUG:  ";

    class abstract_node : public std::enable_shared_from_this<abstract_node>{
    public:
        using AbstractNodeShared = std::shared_ptr<abstract_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_node>;
        using Children = std::vector<AbstractNodeShared>;

        explicit abstract_node(std::string name = "undef"):name_{std::move(name)}{}
        abstract_node(const abstract_node&) = delete;
        abstract_node& operator = (const abstract_node&) = delete;
        abstract_node(const abstract_node&&) = delete;
        abstract_node& operator = (const abstract_node&&) = delete;
        virtual ~abstract_node() = default;

        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeShared {
            return parent_.lock();
        }

        auto set_parent(const AbstractNodeShared&parent)->void {
            parent_ = parent;
        }

        virtual auto get_children()const  ->const  Children& {
            static Children dummy{};
            return dummy;
        }

        virtual auto print_info(std::ostream& os) const  -> void {}

        friend auto operator<<(std::ostream &os, const abstract_node &node)-> std::ostream & {
            node.print_info(os);
            return os;
        }

        auto print() const -> void {
            print_info(std::cout);
            std::cout << std::endl;
            for (const auto& child : get_children()) {
                child->print();
            }
        }

        virtual auto accept(NodeVisitor& v) -> void = 0;

        auto iterate(NodeVisitor& v) -> void {
            for (auto& child : *this)
            {
                v.visit_node(child);
            }
        }

        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = abstract_node;
            using pointer = AbstractNodeShared;  // or also value_type*
            using reference = abstract_node&;  // or also value_type&

            Iterator(pointer ptr = nullptr)
                : current_node(ptr)
            {
                if (current_node == nullptr)
                {
                    the_end();
                }
            }

            reference operator*() { return *current_node; }
            pointer operator->() { return current_node; }

            // Prefix increment
            Iterator& operator++()
            {
                if (!is_end())
                {
                    get_next_child();
                }
                return *this; 
            }

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.current_node == b.current_node; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.current_node != b.current_node; };

        private:

            [[nodiscard]]
            auto is_end() const -> bool
            {
                return (current_node == nullptr);
            }

            auto the_end() -> void
            {
                std::cout << DEBUG_PREFIX << "the end" << std::endl;
                depth = -1;
                current_node = nullptr;
            }

            [[nodiscard]]
            auto go_up_to(pointer ptr) -> bool
            {
                std::cout << DEBUG_PREFIX << "go up from #" << depth << " to #" << (depth - 1) << std::endl;
                current_node = ptr;
                if (--depth <= 0)
                {
                    the_end();
                    return false;
                }
                return true;
            }

            auto go_down_to(pointer ptr) -> void
            {
                std::cout << DEBUG_PREFIX << "go down from #" << depth << " to #" << (depth + 1) << std::endl;
                current_node = ptr;
                ++depth;
            }

            [[nodiscard]]
            auto get_parent() -> bool
            {
                parent_node = current_node->get_parent();
                return (parent_node != nullptr);
            }

            [[nodiscard]]
            auto get_first_child_of_parent() -> bool
            {
                const auto& children = parent_node->get_children();
                if (!children.empty())
                {
                    go_down_to(children[0]);
                    return true;
                }
                return false;
            }

            [[nodiscard]]
            auto find_next_sibling() -> bool
            {
                const auto& children = parent_node->get_children();
                bool found{ false };
                for (auto& child : children)
                {
                    if (found)
                    {
                        current_node = child; // no depth change
                        return true;
                    }
                    found = (child == current_node);
                }
                return false;
            }

            [[nodiscard]]
            auto get_next_sibling() -> bool
            {
                if (depth > 0) // stop at root node
                {
                    if (get_parent())
                    {
                        if (find_next_sibling())
                        {
                            return true;
                        }
                    }
                }
                return false;
            }

            auto get_next_child() -> void
            {
                parent_node = current_node;
                if (!get_first_child_of_parent())
                {
                    while (!get_next_sibling())
                    {
                        if (!go_up_to(parent_node))
                        {
                            the_end();
                            break;
                        }
                    }
                }
            }

        private:
            int depth{ 0 };
            pointer current_node;
            pointer parent_node;
        };

        Iterator begin() { return Iterator(shared_from_this()); }
        Iterator end() { return Iterator(); }

    private:
        AbstractNodeWeak parent_;
        std::string name_;
    };
}
