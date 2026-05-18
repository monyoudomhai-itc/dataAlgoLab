#include <iostream>

using namespace std;

struct Element
{
    int data;
    Element* next;
};

struct Stack
{
    Element* top = nullptr;
    void push(int value)
    {
        Element* e = new Element;

        e->data = value;
        e->next = top;

        top = e;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Display binary number
    void display()
    {
        Element* e = top;

        cout << "Binary representation: ";

        while(e != nullptr)
        {
            cout << e->data;
            e = e->next;
        }

        cout << endl;
    }
};

int main()
{
    Stack s;
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
    int n = number;
    if(n == 0)
    {
        s.push(0);
    }
    while(n > 0)
    {
        int remainder = n % 2;

        s.push(remainder);

        n = n / 2;
    }
    cout << "Decimal number: " << number << endl;
    s.display();
    return 0;
}