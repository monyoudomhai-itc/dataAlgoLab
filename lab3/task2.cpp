#include <iostream>
using namespace std;

int main()
{
    cout<<"Please input n : ";
    int n;cin>>n;
    int *p = &n;
    *p += 7;
    cout<<"Value of n to n +7 : "<<n<<endl;
}