#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Directory : public Node {
private:
    vector<shared_ptr<Node>> children;

public:
    Directory(const string& name);
    void addChild(shared_ptr<Node> child);
    shared_ptr<Node> getChild(string& childName);
    bool removeChild(string& childName);
    void list();
    void print(int level = 0) override;
    size_t size() override;
    shared_ptr<Node> searchFile(const string& filename);
};

#endif  // DIRECTORY_H
