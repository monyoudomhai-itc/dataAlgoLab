#include <iostream>
using namespace std;

struct  Element
{
    /* data */
    int data;
    Element* next;
};
struct List
{
    int n;
    Element* head;
    Element* tail;
    /* data */
};
void insertAtEnd(List* ls,int data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->next = nullptr;
    if(ls->n==0)
    {
        ls->head= temp;
    }
    else 
    {
        ls->tail->next = temp;
    }
    ls->tail=temp;
    ls->n++;
}
void diplay(List* ls)
{
    Element* temp = new Element;
    temp = ls->head;
    cout<<"Total of elements : "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<" , ";
        temp =temp->next;
    }
    cout<<endl;
}
int main ()
{
    List* ls = new List;
    for(int i = 0 ; i< 5;i++)
    {
        cout<<"insert value : "<<i<<endl;
        insertAtEnd(ls,i);
    }
    diplay(ls);
    
    return 0;
}

