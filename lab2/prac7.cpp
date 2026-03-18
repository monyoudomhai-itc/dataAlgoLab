#include <iostream>
using namespace std;

int countChar(string str, char target, int index) {
    // Base case
    if (index == str.length())
        return 0;

    // Check current character
    if (str[index] == target)
        return 1 + countChar(str, target, index + 1);
    else
        return countChar(str, target, index + 1);
}

int main() {
    string str = "recursion example";
    char target = 'e';

    int result = countChar(str, target, 0);

    cout << "Character '" << target << "' appears "
         << result << " times." << endl;

    return 0;
}