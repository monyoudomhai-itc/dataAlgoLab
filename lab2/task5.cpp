#include<iostream>
using namespace std;

int findSum(int a[] , int n)
{
    if(n == 0){
        cout<<a[n]<<" = ";
        return a[n];
    }
    cout<<a[n]<<" + ";
    return a[n]+findSum(a,n-1);
}

int main()
{
    int a[8] = {2,4,5,64,456,456,3,6};
    cout<<"Sum of all elements in Array : "<<findSum(a,7)<<endl;
    return 0;
}

