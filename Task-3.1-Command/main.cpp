//
//  main.cpp
//  Task-3.1-Command
//
//  Created by Маргарет  on 09.08.2024.
//

#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class MessageCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "Get a message: " << message << "\n";
    }
};

class FileCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::ofstream f;
        f.open("file.txt", std::fstream::app);
        if (f.is_open()) {
            f << message << "\n";
        }
        f.close();
    }
};

void print(LogCommand& logcommand, std::string message) {
    logcommand.print(message);
}

int main(int argc, const char * argv[]) {
    MessageCommand messagecom;
    print(messagecom, "Hello");
    FileCommand filecommand;
    print(filecommand, "Hello");
    
    return 0;
}
