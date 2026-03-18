#include <iostream> 
using namespace std;

void star(int n)
{
    if(n == 0){return ;}
    cout<<"*";
    star(n-1);
}
int main()
{
    cout<<"INPUT n for display star(*) n times : ";
    int n ; cin>>n;
    star(n);
    cout<<endl;
    return 0;
}