#ifndef FILE_H
#define FILE_H

#include "Node.h"
#include <iostream>

class File : public Node {
private:
    std::string content;

public:
    File(const std::string& name);
    void write(std::string& data);   
    void read();
    void print(int level = 0) override;
    size_t size() override;
};

#endif