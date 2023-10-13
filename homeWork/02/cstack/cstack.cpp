#include "cstack.hpp"


CStack::CStack(){}





using namespace std;

class Node {
public:
    int data;
    Node* link;

    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int data)
    {

        // создание и выделение памяти в куче
        Node* temp = new Node(data);

        // переполнена ли куча
        // вставка эл-та привела бы к заполнению стека
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        // инициализация данных в поле
        temp->data = data;

        // помещаем ссылку на верхний указатель в врем ссылку
        temp->link = top;

        // делаем temp вершиной стека
        top = temp;
    }

    // проверка стека на заполненность
    bool isEmpty()
    {
        // если top - NULL то эл-ов в стеке нет
        return top == NULL;
    }

    // возврат верхнего эл-та в стеке
    int peek()
    {
        // если стек не пустой то возвращ верхн эл-т
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    // удаление ключа из задан очереди
    void pop()
    {
        Node* temp;

        // проверка переполнения стека
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {

            // присваиваем вернему значению знач temp
            temp = top;

            // второй узел сверху
            top = top->link;

            // автоматич уничтожение связи м/у 1 и 2 узлом; Освобод память верхнего узла - удалить узел
            free(temp);
        }
    }

    // печать всех элементов стека
    void display()
    {
        Node* temp;

        // проверка переполнения стека
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {

                // печать данных узла
                cout << temp->data;

                // временная ссылка на temp
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main()
{
    Stack s;

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    s.display();

    cout << "\nTop element is " << s.peek() << endl;

    s.pop(); //удал
    s.pop();

    s.display();

    cout << "\nTop element is " << s.peek() << endl;

    return 0;
}

CStack::~CStack(){
    //destroy me!)
    clear();
}

void CStack::pop(){

}

void CStack::clear(){

}

void CStack::push(uint32_t val){


}

uint32_t CStack::top(){
    return 0;
}

bool CStack::empty(){
    return ptop==nullptr;
}