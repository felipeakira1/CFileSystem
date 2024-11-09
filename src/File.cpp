#include <iostream>
#include "../include/File.h"

File::File(const std::string& name) : Node(name) {}

void File::write(std::string& data) {
    content = data;
}

void File::read() {
    std::cout << name << ": " << content << std::endl;
}

void File::print(int level) {
    std::cout << std::string(level * 2, ' ') << name << ": " << content << " (" << size() << ")" << std::endl;
}

size_t File::size() {
    return content.size();
}