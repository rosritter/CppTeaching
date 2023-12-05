#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct human{
    char name[40];
    double age=0.01; 
    char town[20];
};

std::ostream& operator<<(std::ostream& stream, const human& being)
{
    stream << being.name << '\t';
    stream << being.town << '\t';
    stream << being.age;
    return stream;
} 

void inputbin(human&being){
    std::fstream in("structbin.bin",std::fstream::in | ios::binary); 
    in.read((char*)&being, sizeof(being));
    in.close();
}
void outputbin(const human&being){
    std::fstream s("structbin.bin",std::fstream::out | ios::binary);
    s.write((char*)&being,sizeof(being));
    s.close();
}
void output(const human&being){

    std::ofstream out("struct1.txt"); 
    out << being.name << ' ';
    out << being.town << ' ';
    out << being.age;
    out.close();
}

void input(human&being){
    std::ifstream in("struct.txt"); 
    //assertm(!in.is_open(),"did not open");
    in >> being.name;
    in >> being.town;
    in >> being.age;
    in.close();
}

int main(){
    human being,comb;
    input(being);
    outputbin(being);
    inputbin(comb);
    output(comb);
    cout << comb << being;
    return 0;
}