#include <iostream> 
using namespace std;

int multi(int m ,int n)
{
    if(n == 0){return 0;}
    return m+multi(m,n-1);
}

int main()
{
    cout<<"Find n x m"<<endl;
    int m , n ;
    cout<<"input m : ";cin>>m;
    cout<<"input n : ";cin>>n;

    cout<<"Multiplication "<<n<<" x "<<m<<" = "<<multi(m,n)<<endl;
    return 0;
}