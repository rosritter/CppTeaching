#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <filesystem>

using namespace std;

class ErrorFilePath{
    public:
    string path;
    ErrorFilePath(string p):path(p){
        ifstream file(path);
        if(!file)
            throw string{"File not found!\n"};
    };
};

struct DBfield{
    uint64_t id;
    string first_name;
    string last_name;
    string email;
    string sex;
    string ip_adress;
    bool married;
    const char* favourite_color = new char[4];
    const char* shirt_size = new char[3];
    const char* age = new char[4];
    friend ostream& operator<<(ostream& is,const DBfield& f);
    friend istream& operator>>(istream& is,const DBfield& f);
    DBfield (vector<string>& data) {
        id = stoi(data[0]);
        first_name = data[1];
        last_name = data[2];
        email = data[3];
        sex = data[4];
        ip_adress = data[5];
        married = (data[6] == "true");
        favourite_color = data[7].c_str();
        shirt_size = data[8].c_str();
        age = data[9].c_str();
    }
};
string toStrFromArr(const char* chars) {
    return string (chars, strlen(chars));
}
ostream& operator<<(ostream& is,const DBfield& f) {
    is << f.id << ',' << f.first_name 
    << ',' << f.last_name << ',' << f.email
    << ',' << f.sex << ',' << f.ip_adress 
    << ',' << (f.married ? "true" : "false")<< ',' << toStrFromArr(f.favourite_color) 
    << ',' << toStrFromArr(f.shirt_size) << ',' << toStrFromArr(f.age) << '\n';
    return is;
}

string getNewFileName(const string& fileName) {
  filesystem::path filePath(fileName);
  string extension = filePath.extension().string();
  string stem = filePath.stem().string();

  int counter = 1;
  string newFileName = fileName;

  while (filesystem::exists(newFileName)) {
    stringstream ss;
    ss << counter;
    newFileName = stem + ss.str() + extension;
    counter++;
  }

  return newFileName;
}

class FileReader{
public:
    string path, path2;
    FileReader(string p, string p2):path(p),path2(p2){};
    void get_separate_str(vector<string>& str_v, const string& str) {
        auto iter = str.begin();
        auto slow_iter = str.begin();
        for(;iter != str.end(); ++iter) {
            if (*iter == ',') {
              str_v.emplace_back(slow_iter, iter);
              slow_iter = iter + 1;
            }
        }
        str_v.emplace_back(slow_iter, iter);
    }
    void is_str_valid(vector<string> v, int str_num) {
        if (v.size() == 10) {
            for (auto c : v[0]) {
                if (isdigit(c)) continue;
                else throw string("Not an ID in row " + to_string(str_num) + "\n");
            }
            regex pattern0(R"(^[\w\.-]+@[\w\.-]+\.\w+$)");
            if (!regex_match(v[3], pattern0)) throw string("Not an email in row " + to_string(str_num) + "\n");
            regex pattern4("(Male|Female|Gender.*|.*gender)|Non-binary");
            if (!regex_match(v[4], pattern4)) throw string("Not an \"sex\" field in row " + to_string(str_num) + "\n");
            regex pattern1(R"(^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})$)");
            if (!regex_match(v[5], pattern1)) throw string("Not an IP in row " + to_string(str_num) + "\n");
            if (v[6] != "true" && v[6] != "false") throw string("Not a \"married\" field in row " + to_string(str_num) + "\n");
            regex pattern3(R"(^#[0-9A-Fa-f]{3}$|^#[0-9A-Fa-f]{6}$)");
            if (!regex_match(v[7], pattern3)) throw string("Not a \"shirt_color\" field in row " + to_string(str_num) + "\n");
            for (auto c : v[9]) {
                if (isdigit(c)) continue;
                else throw string("Not an \"age\" field in row " + to_string(str_num) + "\n");
            }
            regex pattern2(R"(^[2-9XSLM]{1,3}$)");
            if (!regex_match(v[8], pattern2)) throw string("Not a \"shirt size\" field in row " + to_string(str_num) + "\n");
        } else throw string("Not valid row " + to_string(str_num) + "\n");
    }
    void read(){
        fstream file_read(path);
        string str;
        while (getline(file_read, str)) {
            cout << str;
        }
        //DBfield f;
        file_read.close(); //закрыли поток
        //fileIn >> f; //необходимо переопределить оператор ввода для структуры данных
    };
    void is_valid() {
        fstream file_write_from(path);
        string st;
        getline(file_write_from, st);

        for (int i = 2; i < atoi(st.c_str()); i++) {
            string str;
            getline(file_write_from, str);
            vector<string> ans;
            get_separate_str(ans,str);
            is_str_valid(ans, i);
        }
        file_write_from.close();
    }
    void write(){
        is_valid();
        ofstream bin_file(path2, ios::binary | ios::out);
        fstream file_write_from(path);
        string st;
        getline(file_write_from, st);
        bin_file << st << '\n';
        for (int i = 2; i < atoi(st.c_str()); i++) {
            string str;
            getline(file_write_from, str);
            vector<string> ans;
            get_separate_str(ans,str);
            DBfield f(ans);
            bin_file << f;
        }
        file_write_from.close(); //закрыли поток
        bin_file.close();
    };
    void readBinary(){
        //DBfield f;
        //fileInBinary >> f; //необходимо считать данные из бинарного файла в структуру
    };
    void writeBinary(){
        ofstream new_file("../"+getNewFileName(path));
        fstream file_write_from(path2, ios::binary | ios::in);
        string st;
        getline(file_write_from, st);
        new_file << st << '\n';
        for (int i = 2; i < atoi(st.c_str()); i++) {
            string str;
            getline(file_write_from, str);
            vector<string> ans;
            get_separate_str(ans,str);
            DBfield f(ans);
            new_file << f;
        }
        file_write_from.close();
        new_file.close();
    }
};