#include<iostream>
using namespace std;


struct Element
{
    string data;
    Element* next;
    /* data */
};
struct  List 
{
    int n;
    Element* head;
    Element* tail;
    /* data */
};
List* createList()
{
    List* ls = new List;
    ls->n=0;
    ls->tail = nullptr;
    ls->head = nullptr;
    return ls;
}
void addPerson(List* ls ,string data)
{
    Element* e  = new Element;
    e->data = data;
    e->next = ls->head;
    if (ls->n == 0)
    {
        ls->tail = e;
        /* code */
    }
    ls->head =e;
    ls->n++;
}
void display(List* ls)
{
    Element* e = ls->head;
    cout<<"total element "<<ls->n<<" : ";
    while(e!= nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
    }
    cout<<endl;
}

int main()
{
    List* ls = createList();
    addPerson(ls,"Dom");
    addPerson(ls,"Alice");
    addPerson(ls,"Bob");
    addPerson(ls,"Sorak");
    addPerson(ls,"Nana");

    display(ls);
    return 0;
}