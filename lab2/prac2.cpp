#include <iostream>
using namespace std;

int power(int m,int n)
{
    if(n == 0){return 1;}
    
    
    return m*power(m,n-1);
}

int main()
{
    cout<<"Find power n of m"<<endl;
    int m , n ;
    cout<<"input m : ";cin>>m;
    cout<<"input n : ";cin>>n;

    cout<<"Power "<<n<<"of "<<m<<" = "<<power(m,n)<<endl;
    return 0;
}