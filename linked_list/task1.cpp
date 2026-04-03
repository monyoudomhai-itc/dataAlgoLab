#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
};
struct List
{
    int n;//number of element
    Element* head;
    Element* tail;
};

List* createEmpty()
{
    List* ls = new List;
    ls->head=nullptr;
    ls->n=0;
    ls->tail=nullptr;
    
    return ls;
}
void add(List* ls,int data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->next = nullptr;
    if(ls->n == 0)
    {
        ls->head = temp;
    }
    else {
        ls->tail->next= temp;
    }
    ls->tail  = temp;
    ls->n++;
}
void display(List* ls){
    Element* temp = ls->head;
    cout<<"Total of element : "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->next;
    }
    cout<<endl;
}
int main ()
{
    List* ls = createEmpty();
    for (int i = 0 ;i< 5;i++)
    {
        add(ls,(i+2));
    }
    display(ls);
    return 0;
}