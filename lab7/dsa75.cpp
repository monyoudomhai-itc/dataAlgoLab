#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

struct Stack
{
    Node* top;

    Stack()
    {
        top = nullptr;
    }

    void push(char value)
    {
        Node* e = new Node;
        e->data = value;
        e->next = top;
        top = e;
    }

    void pop()
    {
        if(top == nullptr)
            return;

        cout << top->data << " ";

        Node* e = top;
        top = top->next;

        delete e;
    }

    void display()
    {
        Node* e = top;

        while(e != nullptr)
        {
            cout << e->data << " ";
            e = e->next;
        }
        cout<<endl;
    }
};

int main()
{
    string text = "EAS*Y*QUE***ST***IO*N***";

    Stack s;

    cout << "Pop sequence: ";

    for(char c : text)
    {
        if(c == '*')
            s.pop();
        else
            s.push(c);
    }

    cout << endl;

    cout << "Final Stack: ";

    s.display();

    return 0;
}