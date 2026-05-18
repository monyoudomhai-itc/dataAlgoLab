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
List* createEmptyList()
{
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void display(List* ls)
{
    Element* e = ls->head;
    while(e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
    }
    cout<<endl;
}
void addEnd(List* ls,int data){
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    e->prev = ls->tail;
    if(ls->n == 0)
    {
        ls->head = e;
    }
    else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n ++;
}
void addBegin(List* ls,int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    e->prev = nullptr;
    if(ls->n == 0)
    {
        ls->tail = e;
    }
    else
    {
        ls->head->prev = e;
    }
    ls->head = e;
    ls->n++;
}
void addAtPosition(List* ls, int data, int pos)
{
    // Guard: validate list and position bounds
    if (!ls || pos < 0 || pos > ls->n)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // Delegate edge cases to specialized functions
    if (pos == 0)    { addBegin(ls, data); return; }
    if (pos == ls->n){ addEnd(ls, data);   return; }

    // Optimize traversal: start from tail if pos is in the second half
    Element* current = nullptr;
    if (pos <= ls->n / 2)
    {
        current = ls->head;
        for (int i = 0; i < pos - 1; i++)
            current = current->next;
    }
    else
    {
        current = ls->tail;
        for (int i = ls->n - 1; i > pos - 1; i--)
            current = current->prev;
    }

    // Allocate and link new node
    Element* e  = new Element;
    e->data     = data;
    e->prev     = current;
    e->next     = current->next;

    current->next->prev = e;
    current->next       = e;

    ls->n++;
}

int main()
{
    List* ls = createEmptyList();

    cout<<"Add the End"<<endl;
    addEnd(ls,5);
    addEnd(ls , 6);
    display(ls);
    cout<<"Add 7 in postion 1"<<endl;
    addAtPosition(ls,7,1);
    display(ls);
    cout<<"Add the beginning"<<endl;
    addBegin(ls,3);
    addBegin(ls,4);
    display(ls);

    return 0;
}