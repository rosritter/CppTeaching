#include "fStream.hpp"

int main(int argc, char *argv[]){
    try{
        ErrorFilePath err(argv[1]);
        FileReader f(argv[1], argv[2]); //открыть файл
        f.write(); //записать в txt файл
        //f.read();       //считать из файла
        f.writeBinary(); //записать в бинарный файл
        //f.readBinary(); //прочесть из бинарного файла
    }
    catch (const string& err_mess){
        cout << err_mess;
    }
    return 0;
}