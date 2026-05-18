#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
    Element* prev;
    /* data */
};
struct List
{
    int n;
    Element* head;
    Element* tail;
    /* data */
};
void addBegin(List* ls,int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    e->prev = nullptr;
    if(ls->head != nullptr) ls->head->prev = e;
    if(ls->n =0) ls->tail = e;

    ls->head = e;
    ls->n++;
}
List* createEmptyList()
{
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void addLast(List* ls ,int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    e->prev =ls->tail;

    if(ls->n==0) ls->head = e;
    else ls->tail->next =e;
    ls->tail = e;
    ls->n++;
}
void displayForward(List* ls)
{
    Element* e = ls->head;
    while(e != nullptr)
    {
        cout<<e->data <<" ";
        e = e->next ;
    }
    cout<<endl;
}
void displayBackward(List* ls)
{
    Element* e = ls->tail;
    while (e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->prev;
    }
    cout<<endl;
}
void addpos(List* ls , int data,int pos)
{
    if(pos < 0 || pos > ls->n) {
        cout<<"Invalid position"<<endl;
        return ;
    }
    if(pos == 0) {
        addBegin(ls,data);
        return ;
    }
    if(pos == ls->n){

        addLast(ls,data);
        return ;
    }
    Element* current = nullptr;
    if(pos <= ls->n / 2)
    {
        current = ls->head;
        for(int i = 0; i < pos -1;i++)
        {
            current = current->next;
        }
    }
    else {
        current = ls->tail;
        for(int i = ls->n -1 ; i > pos -1; i--)
        {
            current = current->prev;
        }
    }
    Element* e = new Element;
    e->data = data;
    e->next = current->next;
    e->prev = current;

    current->next->prev = e;
    current->next = e;
    ls->n++;
}
void deleteBegin(List* ls)
{
    if(ls->n== 0) return; 
    Element* temp = ls->head;
    ls->head = temp->next;
    if(ls->head != nullptr) ls->head->prev = nullptr;
    else ls->tail = nullptr;
    delete temp;
    ls->n--;
}

void deleteBegin(List* ls,int data)
{
    if(ls->n ==0) return ;
    Element* temp = ls->head;
    if(ls->head!= nullptr) ls->head->prev =nullptr;
    else ls->tail = nullptr;
    delete temp;
     ls->n --;
}
//2 combine to 1
void CombineList(List* list1 , List* list2)
{
    if(list2->n == 0) return ;
    if(list1->n == 0)
    {
        list1->head =list2->head;
        list1->tail = list2->tail;
    }
    else {
        list1->tail = list2->head;
        list2->head->prev = list1->tail;
    }
}
void deleteLast(List* ls)
{
    if(ls->n == 0) return ;
    Element* temp = ls->tail;
    ls->tail = temp->prev;
    if(ls->tail!= nullptr) ls->tail->next = nullptr;
    else ls->head = nullptr;
    delete temp ;
    ls->n--;
}
int main()
{
    return 0;
}