#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
    /* data */
};
struct Stack
{
    Element* top;
    Stack(){
        top = nullptr;
    }
    bool isEmpty() {return (top == nullptr);}

    void push(int data){
        Element* e = new Element;
        e->data = data;
        e->next = top;
        
        top = e;
        cout<<data<<" pushed into stack."<<endl;
    }
    void pop(){
        if(isEmpty()) cout<< "Stack Underflow!"<<endl;
        else {
            Element* e = top;
            cout<<e->data<<" popped from stack."<<endl;
            top = e->next;
            delete e;
        }
    }
    void peek(){
        if(isEmpty()) cout<<"Stack is empty."<<endl;
        else{
            cout<<"Top element is: "<<top->data<<endl;
        }
    }
    int count(){
        int num = 0;
        Element* e = top;
        while(e != nullptr){
            num++;
            e = e->next;
        }
        return num;
    }
    void display(){
        Element* e = top;
        cout<<"Stack element are: ";
        while(e != nullptr){
            cout<<e->data<<" ";
            e = e->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack s = Stack();
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    s.peek();
    cout<<"Number of Elements : "<<s.count()<<endl;
    s.pop();
    s.display();
    cout<<"Number of Elements : "<<s.count()<<endl;
    return 0;
}

