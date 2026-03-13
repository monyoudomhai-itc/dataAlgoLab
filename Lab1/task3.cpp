#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter your name : ";
    string name;
    cin>>name;
    cout<<"Enter your gender(M or F) : ";
    char gender;
    cin>>gender;
    cout<<"Enter your Salary : ";
    float sal ;
    cin>>sal;
    if (gender == 'M')
    {
        if(sal < 300)
        {
            sal = sal ;
        }
        else if(sal<500)
        {
            sal = sal*0.05;
        }
        else if(sal <= 1000)
        {
            sal = sal * 0.07;
        }
        else 
        {
            sal = sal *0.095;
        }
    }
    else
    {
        if(sal < 300) {sal = sal*1;}
        else if (sal < 500){sal = sal *0.035;}
        else if (sal <= 1000){sal = sal * 0.065;}
        else {sal = sal*0.08;}
    }
    cout<<"Hello , "<<name<<endl;
    cout<<"You have to pay "<<sal<<" USD"<<endl;
}