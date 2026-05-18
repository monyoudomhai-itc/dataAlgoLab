#include <iostream> 
using namespace std;

struct Element
{
    int data;
    Element* next;
    /* data */
};
struct List
{
    int n;
    Element* head;
    Element* tail;
    /* data */
};
List* ceateEmpty()
{
    List* ls = new List;
    ls->n =0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void addBegin(List* ls , int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    if(ls->n ==0)
    {
        ls->tail = e;
    }
    ls->head = e;
    ls->n++;
}
void addLast(List* ls , int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if(ls->n==0)
    {
        ls->head = e;
    }
    else{
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n ++;
}
void display(List* ls)
{
    Element* e = ls->head;
    while (e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
    }
    cout<<endl;
}
int main()
{
    return 0;
}