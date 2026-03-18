#include <iostream>
using namespace std;

int main()
{
    int min = 1;
    while (min >= 0){
    cout<<"Enter Minutes convert to Standard time : ";
    cin>>min;
    float hour = min / 60;
    float reMin = min % 60 ;
    float sec = 0 ; 
    cout<<"TIME Converted : "<<hour<<":"<<reMin<<":"<<sec<<endl;
    cout<<"exit program inputer -1 "<<endl;
    }
}