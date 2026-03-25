#include <iostream>
using namespace std;

void exchange(float *a ,float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    float an = 8 , bn = 9;
    float *a = &an;
    float *b = &bn;
    cout<<"Before Exchange : \na = "<<an<<"\n b  = "<<bn<<endl;
    exchange(a,b);
    cout<<"After Exchange : \na = "<<an<<"\n b  = "<<bn<<endl;
    return 0;
}