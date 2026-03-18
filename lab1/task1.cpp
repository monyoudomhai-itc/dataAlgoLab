#include<iostream>
using namespace std;

int main() 
{
    string name ,major ;
    char gender;
    int age;
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<endl;
    cout<<"Please enter your age: ";
    cin>>age;
    cout<<endl;
    cout<<"PLease enter your gender(M or F): ";
    cin>>gender;
    cout<<endl;
    cout<<"PLease enter your major: ";
    cin>>major;
    cout<<endl;
    if (gender =='M' || gender == 'm')
    {
        cout<<"Hi, Mr."<<name<<"!your age is "<<age<<" year old and you learn "<<major<<endl;

    }
    else 
    {
        cout<<"Hi, Mrs."<<name<<"!you are "<<age<<" year old and you are majoring "<<major<<endl;
    }
    if(age>=18)
    {
        cout<<"You are eligible to vote the election ."<<endl;
    }
    else
    {
        cout<<"You are not eligible to vote the election yet."<<endl;
    }
    return 0;
}