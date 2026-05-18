#include <iostream>
using namespace std;

struct Stack{
    int arr[5];
    int top;
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top ==4);
    }
    void push(int data)
    {
        if(isFull()) cout<<"Stack Overflow!"<<endl;
        else{
            top++;
            arr[top] = data;

            cout<<data<<"Push into stack."<<endl;
        }
    }
    void pop(){
        if(isEmpty()) cout<<"Stack Underflow"<<endl;
        else{
            cout<<arr[top]<<" popped from stack"<<endl;

            top--;
        }
    }
    void peek(){
        if(isEmpty()) cout<<"Stack is empty."<<endl;
        else cout<<"Top element is : "<<arr[top]<<endl;
    }
    void display()
    {
        if(isEmpty()) cout<<"Stack is Empty. "<<endl;
        else {
            cout<<"Stack element are : ";

            for(int i = top ; i>= 0;i--){
                cout<<arr[i]<<"<->";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Stack stack = Stack();
    //push mean add
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(50);
    stack.push(45);
    stack.push(34);

    stack.display();

    stack.peek();

    stack.pop();
    stack.pop();

    stack.display();
    stack.peek();
    return 0;
}