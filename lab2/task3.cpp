#include <iostream>
using namespace std;

int min(int a[],int n)
{   
    
    if(n == 0)
    {
        return a[n];
    }
    int numMin = min(a,n-1);
    if(a[n]<numMin)
    {
        return a[n];
    }
    else 
    {
        return numMin;
    }
}
int main()
{
    int a[] = {13,25,33,43,145,5,7};

    cout<<"Minimum of all elements : "<<min(a,6);
    cout<<endl;
    return 0;
}