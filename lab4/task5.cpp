#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
    /* data */
};
struct Listnum
{
    int n;
    Element* head;
    Element* tail;
    /* data */
    void addNum(Listnum* ls,int data)
    {
        Element* e = new Element;
        e->data = data;
        e->next = nullptr;
        if(ls->n==0)
        {
            ls->head = e;
        }
        else {
            ls->tail->next = e;
        }
        ls->tail = e;
        ls->n++;
    }
    void diplayNum(Listnum* ls)
    {
        Element* e = ls->head;
        cout<<"All elements are : ";
        while(e != nullptr)
        {
            cout<<e->data<<", ";
            e = e->next;
        }
    }
    int sum(Listnum* ls)
    {
        Element* e = ls->head;
        int result = 0;
        while(e != nullptr)
        {
            result += e->data;
            e= e->next;
        }
        return result;
    }
};
Listnum* createEmptyNum()
{
    Listnum* ls = new Listnum;
    ls->head = nullptr;
    ls->tail=nullptr;
    ls->n = 0;

    return ls;
}

int main()
{
    Listnum* ls = createEmptyNum();
    int num;
    cout<<"\t A Program to store number as many possible:\n";
    int isZero = 0;
    while(isZero != 2)
    {
        cout<<"Enter a number : ";
        cin>>num;
        ls->addNum(ls,num);
        if(num == 0){
            cout<<"\tYou have entered number 0 once.only 1 more left.\n";
            cout<<"***We will quiit the program***\n";
            isZero ++;}
    }
    cout<<"You have entered the number 0 twice so far.\n";
    cout<<"THe program is going to stop now"<<endl;
    cout<<endl;
    ls->diplayNum(ls);
    cout<<endl;
    cout<<"Summation of all number is : "<<ls->sum(ls)<<endl;
}

