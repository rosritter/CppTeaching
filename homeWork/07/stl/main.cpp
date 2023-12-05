#include "fStream.hpp"

int main(){
    try{
        FileReader f('dbfile.txt') //открыть файл
        f.read();       //считать из файла
        f.writeBinary(); //записать в бинарный файл
        f.readBinary(); //прочесть из бинарного файла
        f.write(); //записать в txt файл
    }
    catch (...){
        //обработка ошибок
    }


    return 0;
}