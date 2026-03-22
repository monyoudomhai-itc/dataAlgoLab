#include <iostream>
using namespace std;
void star(int n)
{
    if (n == 0)
    {
        return;
    }
    cout<<"*";
    star(n-1);
}
void disNum(int n)
{
    if (n == 0){return;}
    cout<<n<<" ";
    disNum(n-1);
}
int main()
{
    int choice = 3,n;
    while (choice!= 0)
    {
    cout<<"--- Welcome to our program ---\n";
    cout<<"1. Display n star (*)\n2.Display number from n to 1\n";
    cout<<"0. Exit\nchoice : ";cin>>choice;
    if(choice ==0){cout<<"\t Exit program ...\n";}
    else if (choice == 1)
    {
        cout<<"--- Display n star ---\nEnter n : ";
        cin>>n;
        star(n);
        cout<<endl;
    }
    else if (choice == 2)
    {
        cout<<"--- Display number from n to 1 ---\nEnter n : ";
        cin>>n;
        disNum(n);
        cout<<endl;
    }
    }
    return 0;
}