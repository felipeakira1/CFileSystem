#include "../include/Directory.h"

Directory::Directory(const std::string& name) : Node(name) {}

void Directory::addChild(const std::shared_ptr<Node>& child) {
    child->setParent(shared_from_this());  // Set parent using shared_ptr
    children.push_back(child);
}

std::shared_ptr<Node> Directory::getChild(const std::string& childName) const {
    for (const auto& child : children) {
        if (child->getName() == childName) {
            return child;
        }
    }
    return nullptr;  // Return nullptr if not found
}

bool Directory::removeChild(const std::string& childName) {
    auto it = std::find_if(children.begin(), children.end(),
                           [&childName](const std::shared_ptr<Node>& node) {
                               return node->getName() == childName;
                           });
    if (it != children.end()) {
        children.erase(it);  // Remove the child
        return true;
    }
    return false;  // Child not found
}

void Directory::list() const {
    if(children.empty()) {
        std::cout << "empty\n";
        return;
    }
    std::vector<std::shared_ptr<Node>> directories;
    std::vector<std::shared_ptr<Node>> files;
    for (const auto& child : children) {
        if (std::dynamic_pointer_cast<Directory>(child)) {
            directories.push_back(child);
        } else {
            files.push_back(child);
        }
    }
    for(const auto& dir : directories) {
        std::cout << dir->getName() << std::endl;
    }
    for(const auto& file : files) {
        std::cout << file->getName() << ".txt (" << file->size() << "bytes)\n";
    }
    std::cout << "\nTotal size: " << size() << " bytes" << std::endl;
}

void Directory::print(int level) const {
    std::cout << std::string(level * 2, ' ') << name << "/\n";
    for (const auto& child : children) {
        child->print(level + 1);
    }
}

size_t Directory::size() const {
    size_t totalSize = 0;
    for (const auto& child : children) {
        totalSize += child->size();
    }
    return totalSize;
}
