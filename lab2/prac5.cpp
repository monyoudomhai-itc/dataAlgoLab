#include <iostream>
using namespace std;

int sum(int num[],int i)
{
    if(i < 0)
    {
        return 0;
    }
    return num[i]+sum(num,i-1);
}
int main()
{
    int num[5] = {1,1,2,1,1};
    cout<<"Sum of all element : "<<sum(num,5)<<endl;
    return 0;
}