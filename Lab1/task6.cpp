#include <iostream> 
using namespace std;

int main ()
{   
    
    while (true){
    cout<<"Find Simulation number from 1 to n except 10 ,30 "<<endl;
    cout<<" Enter Number n (n should >50 ): ";
    int n ,total;
    cin>>n;
    if (n >50){
    for (int i = 0 ; i<=n;i++)
    {
        
        if (i == 10 || i == 30)
        {
            total = total;
        }
        else 
        {
            total = total + i;
        }      
    }
    cout<<"total is "<<total<<endl;
    }
    else if (n == -1 )
    {
        return 0;
    }
    else{
        cout<<"Invalid number"<<endl;
    }
}
}