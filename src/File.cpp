#include <iostream>
#include "../include/File.h"

File::File(const std::string& name) : Node(name) {}

void File::write(const std::string& data) {
    content = data;
}

void File::read() const {
    std::cout << name << ": " << content << std::endl;
}

void File::print(int level) const {
    std::cout << std::string(level * 2, ' ') << name << ": " << content << " (" << size() << ")" << std::endl;
}

size_t File::size() const {
    return content.size();
}