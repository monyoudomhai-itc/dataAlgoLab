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
void insertBegin(List* ls,int data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->next= ls->head;
    if(ls->n == 0){ls->tail = temp;}
    ls->head = temp;
    ls->n++;
}
void display(List* ls)
{
    Element* temp = new Element;
    temp = ls->head;
    cout<<"Total of all elements : "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<< " , ";
        temp = temp->next;
    }
    cout<<endl;

}
int main()
{
    List* ls = new List;
    ls->head = nullptr;
    ls->n = 0;
    ls->tail = nullptr;

    for (int i =0 ; i< 5 ;i++)
    {
        cout<<"insert number : "<<i;
        cout<<endl;
        insertBegin(ls , i);
    }
    display(ls);
    return 0;
}

