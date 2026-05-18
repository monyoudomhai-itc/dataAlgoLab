#include <iostream>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        top++;
        arr[top] = c;
    }

    void pop() {
        if (top != -1) {
            top--;
        }
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool match(char a, char b) {
    if (a == '(' && b == ')')
        return true;

    if (a == '{' && b == '}')
        return true;

    if (a == '[' && b == ']')
        return true;

    return false;
}

int main() {

    Stack s;

    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    bool balanced = true;

    for (char ch : exp) {

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.isEmpty()) {
                balanced = false;
                break;
            }

            char topChar = s.peek();
            s.pop();

            if (!match(topChar, ch)) {
                balanced = false;
                break;
            }
        }
    }

    if (!s.isEmpty()) {
        balanced = false;
    }

    if (balanced)
        cout << "Balanced!" << endl;
    else
        cout << "Not Balanced!" << endl;

    return 0;
}