#include <iostream>
using namespace std;

int sum(int n)
{
    if(n == 0){return 0;}
    if(n%2== 0)
    {
        return sum(n-1);
    }
    else {
        return n + sum(n-1);
    }
}

int main()
{
    cout<<"FInd summation of all odd numbers from 1 to n"<<endl;
    cout<<"Enter n : ";
    int n;cin>>n;
    cout<<"Summation of odd number from 1 to "<<n<<" : "<<sum(n);
    cout<<endl;
    return 0;
}