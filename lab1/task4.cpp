#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
    int user= 0;
    while (user != -1){
    cout<<"Welcome to our Game \nplay Against computer"<<endl;
    cout<<"\n1.ROCK \n2.PAPER\n3.SCISSOR"<<endl;
    cout<<"Choose number : ";
    cin>>user;
    user = user -1;
    int num = rand() % 3;
    // 0 for rock 1 for paper 2 for scissor
    if(user == num)
    {
        cout<<"We are draw"<<endl;
    }
    else if ((user == 0 && num ==1)||(user==1&&num==2)||(user == 2&& num == 0)){
        cout<<"YOU LOSE !"<<endl;
    }
    else if((user == 0 && num == 2)||(user==1 && num ==0)||(user ==2&&num == 1))
    {
        cout<<"YOU WIN!"<<endl;
    }
    cout<<"choose 0 for exit game"<<endl;
}
}