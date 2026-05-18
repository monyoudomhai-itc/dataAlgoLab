#include <iostream>
#include <string>
using namespace std;
struct Element
{
    char data;
    Element* next;
    /* data */
};
struct Stack
{
    Element* top ;
    Stack(){
        top = nullptr;
    }
    void push(char data){
        Element* e = new Element;
        e->data = data;
        e->next = top;
        top = e;
    }
    void display()
    {
        Element* e = top;
        cout<<"The inverse of text : ";
        while(e != nullptr){
            cout<<e->data;
            e = e->next;
        }
        cout<<endl;
    }
};

int main()
{
    Stack s = Stack();
    string text;
    cout<<"\tReverse Order of text"<<endl;
    cout<<"Input text : ";
    getline(cin,text);

    for(char c : text){
        s.push(c);
    }
    s.display();
    return 0;
}