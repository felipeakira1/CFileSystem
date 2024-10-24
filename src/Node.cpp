#include "../include/Node.h"

Node::Node(const std::string& name) : name(name) {}

Node::~Node() {}

std::string Node::getName() const {
    return name;
}

std::shared_ptr<Node> Node::getParent() const {
    return parent.lock();
}

void Node::setParent(const std::shared_ptr<Node>& newParent) {
    parent = newParent;
}
