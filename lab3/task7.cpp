#include <iostream>
using namespace std;

double sum1(double *sum, int n)
{
    if (n == 0){return 0;}
    
    return *sum = 1/(2+(n*10.0)) +  sum1(sum,n-1);
}
int main()
{
    double result;
    sum1(&result, 2);
    cout<<"Result : "<<result<<endl;
    return 0;
}