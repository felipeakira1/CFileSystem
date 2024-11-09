#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
using namespace std;

class Node : public enable_shared_from_this<Node> {
protected:
    string name;
    weak_ptr<Node> parent; 

public:
    Node(const string& name);
    virtual ~Node();
    string getName();
    shared_ptr<Node> getParent() ;
    void setParent(shared_ptr<Node> newParent);

    virtual void print(int level = 0) = 0;
    virtual size_t size() = 0;
};

#endif  // NODE_H
