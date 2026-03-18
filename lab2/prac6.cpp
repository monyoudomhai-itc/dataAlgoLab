#include <iostream>
using namespace std;

int findMin(int num[], int i, int length)
{
    // Base case
    if (i == length - 1)
        return num[i];

    // Recursive call
    int restMin = findMin(num, i + 1, length);

    // Compare current element with minimum of rest
    if (num[i] < restMin)
        return num[i];
    else
        return restMin;
}

int main()
{
    int num[5] = {2, 4, 5, 6, 7};
    cout << findMin(num, 0, 5) << endl;
}