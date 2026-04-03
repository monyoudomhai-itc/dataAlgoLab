#include <iostream>
using namespace std;
void input(int *nump ,int n)
{
    if(n == -1){return;}
    input(nump,n-1);
    cout<<"Value #"<<(n+1)<<" : ";
    cin>>*(nump+n);
    
}
void display(int *nump,int n)
{
    if(n == -1){return ;}
    display(nump,n-1);
    cout<<"Value #"<<(n+1)<<" : "<<*(nump+n)<<endl;
}
int sum(int *nump,int n)
{
    if (n == -1){return 0;}
    return *(nump+n) + sum(nump,n-1);
}
int multi(int *nump,int n)
{
    if(n == -1){return 1;}
    return *(nump+n) *multi(nump,n-1);
}
int main()
{
    int num[7];
    int *nump = num;
    cout<<"Please input 7 numbers : "<<endl;;
    input(nump,6);
    cout<<"\t Display all number "<<endl;
    display(nump,6);
    cout<<endl;
    cout<<"Summation of all element : "<<sum(nump,6)<<endl;
    cout<<"\nMultiplication of all elements : "<<multi(nump,6)<<endl;
    
    return 0;
}