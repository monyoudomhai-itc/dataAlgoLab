#include <iostream>
using namespace std;

// int main ()
// {
//     int n1 = 7,n2=3,n3=15;
//     int *p1= &n1;
//     int *p2 = &n2;
//     int *p3=&n3;
//     cout<<"Address of n1 : "<<p1<<", value of n1 : "<<*p1<<endl;
//     *p3 = n1 +n2;
//     cout<<"n3 : "<<n3<<endl;
// }
void exchange(int *ap , int *bp)
{
    int temp;
    temp = *ap;
    *ap = *bp;
    *bp = temp;
}
int main()
{
    // int n;
    // int *p = &n;
    // cout<<"Please input N :";cin>>n;
    // *p += 7;
    // cout<<"Value of n : "<<n<<endl;
    int a = 5 , b =8;
    int *ap = &a ,*bp = &b;
    exchange(ap,bp);
    cout<<" A : "<<a<<" B : "<<b<<endl;
    return 0;
}