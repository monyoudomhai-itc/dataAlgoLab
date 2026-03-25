#include <iostream>
#include <cmath>
using namespace std;

void solveEquation(int a,int b,int c,float *x1p,float *x2p,float *deltap)
{
    *deltap = b*b - (4*a*c);
    *x1p = (-b +sqrt(*deltap))/(2*a);
    *x2p = (-b -sqrt(*deltap))/(2*a);
}
int main()
{
    cout<<"Solve quadratic equation ax^2 + bx +c = 0 where a != 0"<<endl;
    float x1 ,x2,delta;
    float *x1p = &x1;
    float *x2p = &x2;
    float *deltap = &delta;
    cout<<"Enter number : "<<endl;
    cout<<" a: ";int a ;cin>>a;
    cout<<" b: ";int b; cin>>b;
    cout<<" c: ";int c;cin>>c;
    solveEquation(a,b,c,x1p,x2p,deltap);
    cout<<"Answer : "<<"\nx1 = "<<x1<<"\nx2 = "<<x2<<endl;
    return 0;
}