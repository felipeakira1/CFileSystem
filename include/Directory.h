#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Directory : public Node {
private:
    std::vector<std::shared_ptr<Node>> children;

public:
    Directory(const std::string& name);
    void addChild(const std::shared_ptr<Node>& child);
    std::shared_ptr<Node> getChild(const std::string& childName) const;
    bool removeChild(const std::string& childName);
    void list() const;
    void print(int level = 0) const override;
    size_t size() const override;
};

#endif  // DIRECTORY_H
