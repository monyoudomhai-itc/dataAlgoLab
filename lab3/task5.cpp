#include <iostream>
using namespace std;

void findMaxMin(int *arrp,int *maxp,int *minp)
{
    *maxp = *arrp;
    *minp = *arrp;
    for(int i = 0 ; i < 7;i++)
    {
        if(*(arrp+i)<*minp)
        {
            *minp = *(arrp+i);
        }
        if(*(arrp+i)>*maxp)
        {
            *maxp= *(arrp+i);
        }
    }

}
int main()
{
    int arr[7];
    int *arrp = arr;
    int max , min;
    int *maxp =  &max;
    int *minp = &min;
    cout<<"=== Find Maximum and Minimum ===\n";
    for(int i = 0 ;i <7 ;i++)
    {
        cout<<"Value #"<<(i+1)<<" : ";
        cin>>arr[i];
    }
    findMaxMin(arrp,maxp,minp);
    cout<<endl;
    cout<<"Maximum : "<<max<<endl;
    cout<<"Minimum : "<<min<<endl;
    return 0;
}