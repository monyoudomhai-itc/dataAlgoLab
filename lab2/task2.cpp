#include <iostream>
using namespace std;

int sum(int num)
{
    if (num == 0){return 0;}
    if(num % 2 != 0){
    return num+sum(num-1);
    }
    else {
        return sum(num-1);
    }
}
int power(int m ,int n)
{
    if(n == 0){return 1;}

    return m*power(m,n-1);
}
int sumSq(int n)
{
    if (n == 0){return 0;}
     return n*n + sumSq(n-1);
}
int sumDe(int n)
{
    if(n == 0)
    {
        return 0; 
    }
    return (n%10)+sumDe(n/10);
}
int main()
{
    int choice = 1,n, m;
    while (choice != 0)
    {
        cout<<"\tWelcome to our program\n";
        cout<<"1.power m^n\n2.summation 1^2 + 2^2 + .. +n^2\n";
        cout<<"3.sum digit of number \n";
        cout<<"0. Exit \n";
        cin>>choice; 
        switch (choice)
        {
        case 0:
            cout<<"Exit program..."<<endl;
            break;
        case 1:
            cout<<"--- Calculate m^n----\n";
            cout<<"Input m : ";cin>>m;
            cout<<"Input n : ";cin>>n;
            cout<<"Result : "<<power(m, n)<<endl;
            break;
        case 2:
            cout<<"--- Summation 1^2 + 2^2 + .. +n^2\n";
            cout<<"Input n : ";cin>>n;
            cout<<"Result : "<<sumSq(n)<<endl;
            break;
        case 3:
            cout<<"--- Sum the digits of number ---"<<endl;
            cout<<"Input n : ";cin>>n;
            cout<<"Result : "<<sumDe(n)<<endl;
            break;
        default:
            cout<<"Invalid choice\n";
            break;
        }
    }
}