#pragma once
#include <string>

class ErrorFilePath{
    public:
    ErrorFilePath(){};
    void what();
};

struct DBfield{

};

class FileReader{
public:
    std::string path;
    FileReader(std::string p):path(p){};
    void read(){
        DBfield f;
        fileIn >> f; //необходимо переопределить оператор ввода для структуры данных
    };
    void write(){
        DBfield f;
        fileOut << f; //необходимо переопределить оператор вывода для структуры данных
    };
    void readBinary(){
        DBfield f;
        fileInBinary >> f; //необходимо считать данные из бинарного файла в структуру
    };
    void writeBinary(){
        DBfield f;
        fileOutBinary << f; //необходимо записать данные в бинарный файла из структуры
    }
};