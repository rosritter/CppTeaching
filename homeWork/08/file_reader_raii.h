#include <cstdio>
#include <exception>
#include <string>
#include <cstring>
class CannotOpenFileException {
};
 
class FileRaiiWrapper {
private:
    std::FILE* f; // тот самый файловый дескриптор, который мы оборачиваем

public:
    // если файл не открылся, например его нет на диске, то нужно выбросить ошибку CannotOpenFileException
    FileRaiiWrapper(const std::string& name) {
       f = fopen(name.c_str(),"r");
       if (!f) throw new CannotOpenFileException;
    }

    FileRaiiWrapper(const FileRaiiWrapper&) = delete;
    FileRaiiWrapper& operator = (const FileRaiiWrapper&) = delete;


// File&& — ссылка на временный объект
// забираем владение дескриптором у временного объекта other
    // Конструктор перемещения
    FileRaiiWrapper(FileRaiiWrapper&& other) noexcept : f(other.f){
        other.f = nullptr;
    }

    // Оператор присваивания с семантикой перемещения
    FileRaiiWrapper& operator = (FileRaiiWrapper&& other) noexcept {
        if (this != &other) {
            delete f;
            f = other.f;
            other.f = nullptr;
        }
        return *this;
    }

    // Закрываем файл, но только если он валидный
    ~FileRaiiWrapper() noexcept {
        if(f) fclose(f);
    }

    // функция для чтения строки длинной bytes_count из файла
    std::string ReadBytes(const size_t bytes_count) const {
        char* buf = new char[bytes_count + 1]{};
        std::ignore = std::fgets(buf, bytes_count, f);
        return buf;
    }
};