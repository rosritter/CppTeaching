#include "cstack.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <map>

/*
Команды в терминале:
exit - вывод содержимого всех созданных stack и node, выход и программы
Cstack название_стека - создать стек
название_стека push добавлемый_элемент - добавить элемент в стек 
название_стека *= число - умножить все элементы стека на число
название_стека clear - очистить стек
название_стека pop - удалить верхний элемент стека
название_стека top - вывести верхний элемент стека
название_стека empty? - проверить, пуст ли стек 
название_стека get n - получить элемент стека с индексом n
название_стека1 = название_стека2 - скопировать содержимое стека в другой пустой стек 
Node название_node - создать Node
название_node info присваиваемое_значение - присовить значение Node
название_node1 < название_node2 - проверить, меньше ли первый второго
*/

void createCStack(std::map<std::string, CStack>& stacks, const std::string& stackName) {
    CStack newStack;
    stacks[stackName] = newStack;
}

void createNode(std::map<std::string, Node>& nodes, const std::string& nodeName) {
    Node newNode;
    newNode.info = 0; 
    nodes[nodeName] = newNode;
}

void processStackCommand(const std::string& cmd, std::map<std::string, CStack>& stacks, std::istringstream& iss) {
    std::string operation;
    iss >> operation;

    if (operation == "push") {
        uint32_t value;
        iss >> value;
        stacks[cmd].push(value);

    } else if (operation == "pop") {

        if (!stacks[cmd].empty()) {
            stacks[cmd].pop();
        } else {
            std::cout << "Стек " << cmd << " пуст, невозможно выполнить pop." << std::endl;
        }

    } else if (operation == "top") {

        if (!stacks[cmd].empty()) {
            std::cout << cmd << ".top() = " << stacks[cmd].top() << std::endl;
        } else {
            std::cout << "Стек " << cmd << " пуст, невозможно получить top." << std::endl;
        }

    } else if (operation == "empty?") {

        if (stacks[cmd].empty()) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }

    } else if (operation == "get") {

        if (stacks[cmd].empty()) {
            std::cout << "Стек " << cmd << " пуст." << std::endl;
        } else {
            size_t index;
            iss >> index;
            try {
                std::cout << cmd << "[" << index << "] = " << stacks[cmd][index] << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        }
    } else if (operation == "=") {
        std::string otherStackName;
        iss >> otherStackName;

        if (stacks.find(otherStackName) != stacks.end()) {
            stacks[cmd] = stacks[otherStackName];
            } else {
                std::cout << "Стек " << otherStackName << " не найден." << std::endl;
                }

    } else if (operation == "*=") {
        uint32_t multiplier;
        iss >> multiplier;
        stacks[cmd] *= multiplier;

    } else if (operation == "clear") {
        stacks[cmd].clear();
       
    } else {
        std::cout << "Неизвестная команда для стека " << cmd << "." << std::endl;
    }
}

void processNodeCommand(const std::string& cmd, std::map<std::string, Node>& nodes, std::istringstream& iss) {
    std::string operation;
    iss >> operation;

    if (operation == "info") {
        uint32_t value;
        iss >> value;
        nodes[cmd].info = value;
        
    } else if (operation == "<") {
        std::string targetNodeName;
        iss >> targetNodeName;
        if (nodes.find(targetNodeName) != nodes.end()) {
            if (nodes.find(cmd) != nodes.end()) {
                if (nodes[cmd].info < nodes[targetNodeName].info) {
                    std::cout << "Congratulations!"<< std::endl;
                } else {
                    std::cout << "Commiserations!"<< std::endl;
                }
            } else {
                std::cout << "Node " << cmd << " не найден." << std::endl;
            }
        } else {
            std::cout << "Node " << targetNodeName << " не найден." << std::endl;
        }
    } else {
        std::cout << "Неизвестная команда для Node " << cmd << "." << std::endl;
    }
}

int main() {
    std::map<std::string, CStack> stacks;
    std::map<std::string, Node> nodes;

    while (true) {
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            for (const auto& stack : stacks) {
                std::cout << "Содержимое stack " << stack.first << ": ";
                CStack temp = stack.second;
                while (!temp.empty()) {
                    std::cout << temp.top() << " ";
                    temp.pop();
                }
                std::cout << std::endl;
            }

            for (const auto& node : nodes) {
                std::cout << "Содержимое node " << node.first << ": " << node.second.info << std::endl;
            }
            break;
        }

        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "Cstack") {
            std::string stackName;
            iss >> stackName;
            createCStack(stacks, stackName);
        } else if (cmd == "Node") {
            std::string nodeName;
            iss >> nodeName;
            createNode(nodes, nodeName);
        } else if (stacks.find(cmd) != stacks.end()) {
            processStackCommand(cmd, stacks, iss);
        } else if (nodes.find(cmd) != nodes.end()) {
            processNodeCommand(cmd, nodes, iss);
        } else {
            std::cout << "Неверный запрос" << std::endl;
        }
    }

    return 0;
}
