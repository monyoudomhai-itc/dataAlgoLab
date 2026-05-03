#include <iostream>
using namespace std;

struct Element
{
    string data;
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
List* createList()
{
    List* ls = new List;
    ls->n= 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    
    return ls;
}
void addPerson(List* ls,string data){
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
void display(List* ls)
{
    Element* e = ls->head;
    cout<<"Total Elemenets : "<<ls->n<<":"<<endl;
    while (e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
        /* code */
    }
    cout<<endl;
}


int main ()
{
    List* ls = createList();
    addPerson(ls,"A");
    addPerson(ls,"B");
    addPerson(ls,"C");
    addPerson(ls,"D");
    display(ls);
    return 0;
}