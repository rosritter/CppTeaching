/**
 * @file main.cpp
 * @brief задача написать программу, которая будет обслуживать текстовую key-value базу данных в файле db.txt
 * 
 * Должен компилироваться бинарник db, и откликаться на команды (команды подаются как аргументы при запуске приложения *argv)
 * `INSERT KEY=VALUE` - операция вставки пары в базу данных (если добавляется ключ который уже есть в файле, то он обновляется)
 * `DELETE VALUE` - удалить все записи из базы данных, которые содержат значения VALUE (именно значение, а не ключ)
 * `FIND KEY` - вывести значение по ключу в базе данных (возврашает сообщение с элементов в консоль `FOUND: KEY=VALUE`,
 *              или выдаёт на вывод `KEY NOT FOUND`, если элемента нет в базе данных; после `FOUND: KEY=VALUE` или `KEY NOT FOUND` вывести символ конца строки)
 * `PRINT KEYS/VALUES` - вывести значение всех ключей/значений в базе данных (каждое должно заканчиваться символом конца строки '\n' или endl)
 * `DROPALL` - удалить всю базу данных (все значения из базы)
 * Любая команда должна заканчиваться на '?' , можно обрабатывать сразу несколько команд
 * 
 * (используют символы букв и цифр, не используют знаки и не используют пробелы)
 * Как вы будете хранить в файле данные - на ваше усмотрение. Главное - чтобы пользовательское API не нарушалось.
 * Главное - база данных храниться в файле, но не в памяти и программу запускаем по необходимости.
 * Программа может быть неоптимальна с точки зрения вычислений, главное чтобы правильно выполнялась основная логика команд.
 */

#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <exception>

using namespace std;

namespace {
    constexpr char end_command_delimiter{'?'};
}


class FileReader {
public:
    map<string, int> ReadBinaryFile(const string& filename) {
        map<string, int> data;

        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw string("Failed to open file");
            return data;
        }

        string key;
        int value;

        while (file >> key >> value) {
            data[key] = value;
        }

        file.close();
        return data;
    }
};

class FileWriter {
public:
    void WriteBinaryFile(const string& filename, const map<string, int>& data) {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw string("Failed to open file\n");
        }

        for (const auto& pair : data) {
            const string& key = pair.first;
            int value = pair.second;

            file << key << " " << value << "\n";
        }

        file.close();
    }
};

class KeyValueDB {
public:
    void Insert(const string& key, const string& value) {
        if (database_.find(key) != database_.end()) {
            cout << "Key already exists\n";
            return;
        }

        database_[key] = stoi(value);
        cout << "Insert successful\n";
        return;
    }

    void Delete(const string& value) {
        auto it = database_.begin();
        while (it != database_.end()) {
            if (it->second == stoi(value)) {
                it = database_.erase(it);
            } else {
                ++it;
            }
        }
    }

    int Find(const string& key) const {
        auto iter = database_.find(key);
        if (iter == database_.end()) {
            throw string("NOT FOUND\n");
        }

        cout << "FOUND: " << key <<"="<< iter->second << "\n";
        return iter->second;
    }

    void PrintKeys() const {
        if (database_.empty()) {
            cout << "Database is empty\n";
            return;
        }

        for (const auto& pair : database_) {
            cout << pair.first << "\n";
        }
    }

    void PrintValues() const {
        if (database_.empty()) {
            cout << "Database is empty\n";
            return;
        }
        for (const auto& pair : database_) {
            cout << pair.second << "\n";
        }
    }

    void DropAll() {
        database_.clear();
        cout << "All keys and values are dropped\n";
    }
    map<string, int> database_;
};

class KeyValueManager : public KeyValueDB {
public:
    string path;
    KeyValueManager(string path) : path(path) {
        FileReader fr;
        database_ = fr.ReadBinaryFile(path);
    };
};

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char** argv) : argc_(argc), argv_(argv) {}

    bool ProcessNextCommand(KeyValueManager& manager) {
        if (command_index_ >= argc_) {
            return false;
        }
        
        string command = argv_[command_index_];
        ++command_index_;
        if (command == "INSERT") {
            ProcessInsertCommand(manager);
        } else if (command == "DELETE") {
            ProcessDeleteCommand(manager);
        } else if (command == "FIND") {
            ProcessFindCommand(manager);
        } else if (command == "PRINT" && command_index_ < argc_) {
            string print_command = argv_[command_index_];
            print_command.pop_back();
            ++command_index_;
            if (print_command == "KEYS") {
                manager.PrintKeys();
            } else if (print_command == "VALUES") {
                manager.PrintValues();
            }
            else throw string("UNKNOWN COMMAND");
        } else if (command == "DROPALL?") {
            manager.DropAll();
        }

        return true;
    }

private:
    int argc_;
    char** argv_;            
    int command_index_{1};  

    void ProcessInsertCommand(KeyValueManager& manager) {
        if (command_index_ < argc_) {
            string key_value = argv_[command_index_];
            IsCommandValid(key_value);
            ++command_index_;

            size_t separator_pos = key_value.find('=');
            if (separator_pos != string::npos) {
                string key = key_value.substr(0, separator_pos);
                string value = key_value.substr(separator_pos + 1);

                manager.Insert(key, value);
            } else {
                cout << "Incorrect format for INSERT command\n";
            }
        } else {
            cout << "Insufficient arguments for INSERT command\n";
        }
    }

    void ProcessDeleteCommand(KeyValueManager& manager) {
        if (command_index_ < argc_) {
            string value = argv_[command_index_];
            ++command_index_;
            value.pop_back();
            manager.Delete(value);
        } else {
            cout << "Insufficient arguments for DELETE command\n";
        }
    }

    void ProcessFindCommand(KeyValueManager& manager) {
        if (command_index_ < argc_) {
            string key = argv_[command_index_];
            ++command_index_;
            key.pop_back();
            manager.Find(key);
        } else {
            cout << "Insufficient arguments for FIND command\n";
        }
    }

    void IsCommandValid(const string& command) const {
        size_t separator_pos = command.find('=');
        if (separator_pos != string::npos) {
            string key = command.substr(0, separator_pos);
            string value = command.substr(separator_pos + 1);
            value.pop_back();
            if (command.back() != end_command_delimiter)
                throw string("INVALID KEY AND VALUE\n");
        }
    }
};

int main(int argc, char** argv)
{
    try {

        auto db = KeyValueManager("db.txt");
        auto ap = ArgumentsParser(argc, argv);
        while(ap.ProcessNextCommand(db)) {
            FileWriter fw;
            fw.WriteBinaryFile(db.path, db.database_);
        }

    } catch(const string& err_mess) {
        cout << err_mess;
    }

    return 0;
}