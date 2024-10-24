#include <iostream>
#include <vector>
#include <memory>
#include "../include/Directory.h"
#include "../include/File.h"
#include "../include/Utils.h"
#include <sstream>

std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void showHelp() {
    std::cout << "Commands:\n"
              << "  list - List files and directories\n"
              << "  createdir <name> - Create a directory\n"
              << "  createfile <name> - Create a file\n"
              << "  writefile <name> <content> - Write content to a file\n"
              << "  readfile <name> - Read content from a file\n"
              << "  remove <name> - Remove a file or directory (must be empty)\n"
              << "  cd <name> - Change directory\n"
              << "  printpath - Print the current path\n"
              << "  help - Show this help menu\n"
              << "  exit - Exit the program\n";
}

int main() {
    auto root = std::make_shared<Directory>("root");
    auto current = root;

    std::cout << "Welcome to the file system!\n"
              << "Type 'help' to see available commands.\n";

    std::string input;
    while (true) {
        std::cout << getCurrentPath(current) << "> ";
        std::getline(std::cin, input);
        auto tokens = tokenize(input);
        if (tokens.empty()) continue;

        std::string command = tokens[0];
        if (command == "exit") {
            break;
        } else if (command == "help") {
            showHelp();
        } else if (command == "list") {
            current->list();
        } else if (command == "createdir") {
            if (tokens.size() < 2) {
                std::cout << "Usage: createdir <name>\n";
                continue;
            }
            auto newDir = std::make_shared<Directory>(tokens[1]);
            newDir->setParent(current);
            current->addChild(newDir);
        } else if (command == "createfile") {
            if (tokens.size() < 2) {
                std::cout << "Usage: createfile <name>\n";
                continue;
            }
            auto newFile = std::make_shared<File>(tokens[1]);
            current->addChild(newFile);
        } else if (command == "cd") {
            if (tokens.size() < 2) {
                std::cout << "Usage: cd <name>\n";
                continue;
            }
            if(tokens[1] == "..") {
                if(auto parent = current->getParent()) {
                    current = std::dynamic_pointer_cast<Directory>(parent);
                } else {
                    std::cout << "Already at root\n";
                }
            } else {
                auto node = current->getChild(tokens[1]);
                if (!node) {
                    std::cout << "Directory not found\n";
                } else if (auto dir = std::dynamic_pointer_cast<Directory>(node)) {
                    current = dir;
                } else {
                    std::cout << "Not a directory\n";
                }
            }
        } else if (command == "printpath") {
            std::cout << getCurrentPath(current) << '\n';
        } else if (command == "remove") {
            if (tokens.size() < 2) {
                std::cout << "Usage: rm <name>\n";
                continue;
            }
            if (!current->removeChild(tokens[1])) {
                std::cout << "File or directory not found\n";
            }
        } else if (command == "writefile") {
            if (tokens.size() < 3) {
                std::cout << "Usage: writefile <name> <content>\n";
                continue;
            }
            auto node = current->getChild(tokens[1]);
            if (!node) {
                std::cout << "File not found\n";
            } else if (auto file = std::dynamic_pointer_cast<File>(node)) {
                std::string content = input.substr(input.find(tokens[2]));
                file->write(content);
            } else {
                std::cout << "Not a file\n";
            }
        } else if (command == "readfile") {
            if (tokens.size() < 2) {
                std::cout << "Usage: readfile <name>\n";
                continue;
            }
            auto node = current->getChild(tokens[1]);
            if (!node) {
                std::cout << "File not found\n";
            } else if (auto file = std::dynamic_pointer_cast<File>(node)) {
                file->read();
            } else {
                std::cout << "Not a file\n";
            }
        } else {
            std::cout << "Unknown command\n";
        }
    }

    std::cout << "Exiting the file system. Goodbye!\n";
    return 0;
}
