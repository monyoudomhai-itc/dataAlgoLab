#include <iostream>
using namespace std;

int sumNumbers() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num == -1) {
        return -1;
    }

    return num + sumNumbers();
}

int main() {
    int total = sumNumbers();
    cout << "Total = " << total << endl;
    return 0;
}