#include <iostream> 
using namespace std;

int power(int m,int n)
{
    //base case 
    if(n == 0){return 1;}
    return m * power(m , n-1); 
}
int sumSquare(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return n*n + sumSquare(n-1);
}
int sum(int n)
{
    if(n == 0) {
        return 0;
    }
    return n + sum(n-1);
}
int sumOddNumber(int n){
    if(n == 0)
    {
        return 0;
    }
    else if(n % 2 == 0)
    {
        return sumOddNumber(n-1);
    }
    else 
    {
        return n + sumOddNumber(n-1);
    }
}
void display(int n)
{
    if(n == 0)
    {
        return ;
    }
    cout<<"*";
    display(n-1);
}
void displayNtoOne(int n)
{
    if(n == 0)
    {
        return ;
    }
    cout<<n<<" ";
    displayNtoOne(n-1);
}
int findMax(int a[],int n)
{
    if(n == 0)
    {
        return a[n];
    }
    int max = findMax(a,n-1);
    if(a[n] > max)
    {
        return a[n];
    }    
    else{
        return max;
    }
}
int findMin(int a[] , int n)
{
    if(n == 0)
    {
        return a[n];
    }
    int min = findMin(a,n-1);
    if(a[n]< min)
    {
        return a[n];
    }
    else {
        return min;
    }
}
int findSum(int a[] , int n){
    if(n== 0)
    {
        return a[n]; 
    }
    return a[n] + findSum(a,n-1);
}
int main()
{
    cout<<power (3,4)<<endl;
    cout<<sum(5)<<endl;
    cout<<sumSquare(3)<<endl;
    cout<<sumOddNumber(9)<<endl;
    display(10);
    cout<<endl;
    displayNtoOne(10);
    cout<<endl;
    int a[] = {1,2,3,4,5,6,7};
    cout<<findMax(a,7)<<endl;
    cout<<findMin(a,6)<<endl;
    cout<<findSum(a,7)<<endl;
    return 0;
}