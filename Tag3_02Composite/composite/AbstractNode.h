//
// Created by JoachimWagner on 02.04.2025.
//

#pragma once
#include <memory>
#include<vector>

#include <string>

class AbstractNode: public std::enable_shared_from_this<AbstractNode>{
public:
    using AbstractNodeShared = std::shared_ptr<AbstractNode>;
    using AbstractNodeWeak = std::weak_ptr<AbstractNode>;
    using Children = std::vector<AbstractNodeShared>;


    explicit AbstractNode(const std::string &name="undef") : name_(name) {}
    AbstractNode (const AbstractNode & other) = delete;
    AbstractNode (AbstractNode && other) = delete;
    AbstractNode & operator = (const AbstractNode & other) = delete;
    AbstractNode & operator = (AbstractNode && other) = delete;

    virtual ~AbstractNode() = default;

    const std::string &getName() const {
        return name_;
    }

    void setName(const std::string &name) {
        name_ = name;
    }

    const AbstractNodeWeak &getParent() const {
        return parent_;
    }

    void setParent(const AbstractNodeWeak &parent) {
        parent_ = parent;
    }

    virtual const Children & getChildren() const {
        static Children dummy{};
        return dummy;
    }

    virtual void print(std::ostream &os)const{
        os << std::string{"name: "} << this->getName();
    }
    friend auto operator<<(std::ostream &os, const AbstractNode &node)-> std::ostream & {
        node.print(os);
        return os;
    }

private:
    std::string name_;
    AbstractNodeWeak parent_;
};
