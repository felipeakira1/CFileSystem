#include "../include/Utils.h"

std::string getCurrentPath(const std::shared_ptr<Node>& current) {
    if (current->getParent() == nullptr) { // Raiz
        return "/" + current->getName();
    }
    std::string path = "";
    std::shared_ptr<Node> temp = current;
    do {
        path = "/" + temp->getName() + path;
        temp = temp->getParent();
    } while(temp != nullptr);
    return path;
}
