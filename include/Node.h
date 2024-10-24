#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>

class Node : public std::enable_shared_from_this<Node> {
protected:
    std::string name;
    std::weak_ptr<Node> parent; 

public:
    Node(const std::string& name);
    virtual ~Node();
    std::string getName() const;
    std::shared_ptr<Node> getParent() const;
    void setParent(const std::shared_ptr<Node>& newParent);

    virtual void print(int level = 0) const = 0;
    virtual size_t size() const = 0;
};

#endif  // NODE_H
