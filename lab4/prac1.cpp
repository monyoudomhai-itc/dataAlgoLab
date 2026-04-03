#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
};
struct List{
    int n ; // number of element
    Element* head;
    Element* tail;
};
void addInTheEnd(List* ls, int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if(ls->n == 0)
    {
        ls->head = e;
    } 
    else{
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}
void addBegin(List* ls, int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    if(ls->n == 0)
    {
        ls->tail = e;
    }
    ls->head = e;
    ls->n++;
}
void display(List* ls)
{
    Element* temp = ls->head;
    cout<<"Number of elements : "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<"\n";
        temp = temp-> next;
    }
}
// Inserts a node before logical position p (0-based). Out-of-range values are clamped.
void addBeforePosition(List* ls, int data, int p)
{
    if(ls == nullptr)
    {
        return;
    }
    if(p <= 0 || ls->n == 0)
    {
        addBegin(ls, data);
        return;
    }
    if(p >= ls->n)
    {
        addInTheEnd(ls, data);
        return;
    }
    Element* prev = nullptr;
    Element* current = ls->head;
    for(int i = 0; i < p; ++i)
    {
        prev = current;
        current = current->next;
    }
    Element* e = new Element;
    e->data = data;
    e->next = current;
    prev->next = e;
    ls->n++;
}

// Inserts a node after logical position p (0-based). Values past the tail append.
void addAfterPosition(List* ls, int data, int p)
{
    if(ls == nullptr)
    {
        return;
    }
    if(ls->n == 0)
    {
        addBegin(ls, data);
        return;
    }

    if(p < 0)
    {
        p = 0;
    }

    Element* current = ls->head;
    for(int i = 0; i < p && current->next != nullptr; ++i)
    {
        current = current->next;
    }

    Element* e = new Element;
    e->data = data;
    e->next = current->next;
    current->next = e;

    if(current == ls->tail)
    {
        ls->tail = e;
    }
    ls->n++;
}
int main()
{   
    List* lists = new List;
    lists->n = 0;
    lists->head = nullptr;
    lists->tail = nullptr;
    for(int i = 9 ;i > 0;i--)
    {
        addBegin(lists, (i +2));
    }
    display(lists);
    cout<<"\n";
    for(int i = 9 ;i > 0;i--)
    {
        addInTheEnd(lists, (i +2));
    }
    display(lists);
    cout<<"add element 67 before position 6\n";
    addBeforePosition(lists,67,6);
    display(lists);
    cout<<"add element 67 after position 1\n";
    addAfterPosition(lists,67,1);
    display(lists);

    return 0;
}