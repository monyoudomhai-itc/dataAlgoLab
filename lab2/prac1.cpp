#include <iostream>
using namespace std; 
int sum(int n)
{
    int m = n*n;
    if(n==0){
        return 0;
    }
    
    return m + sum(n-1);
}

int main()
{
    int n ,s;
    cout<<"Calculaing Summation S = 1^2+2^2+n^2 \n";
    cin>>n;
    cout<<"sum: "<<sum(n)<<endl;;
    
    return 0;
}