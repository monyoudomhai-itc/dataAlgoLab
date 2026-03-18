#include <iostream>
using namespace std;

int sum(int num)
{
    if (num == 0){return 0;}
    return num+sum(num-1);
}
int main()
{
    cout<<"1.summation from 1 to n"<<endl;
    cout<<"2.power m^n\n3.summation 1^2 + 2^2 + .. +n^2\n";
    cout<<"4.sum digit of number \n";
}