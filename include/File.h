#ifndef FILE_H
#define FILE_H

#include "Node.h"
#include <iostream>

class File : public Node {
private:
    std::string content;

public:
    File(const std::string& name);
    void write(const std::string& data);   
    void read() const;
    void print(int level = 0) const override;
    size_t size() const override;
};

#endif