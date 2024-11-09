#include "../include/Node.h"

Node::Node(const string& name) : name(name) {}

Node::~Node() {}

string Node::getName() {
    return name;
}

shared_ptr<Node> Node::getParent() {
    return parent.lock();
}

void Node::setParent(shared_ptr<Node> newParent) {
    parent = newParent;
}
