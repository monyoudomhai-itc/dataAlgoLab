#include<iostream> 
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
void add(List* ls ,int data)
{
    Element* temp= new Element;
    temp->data =data;
    temp->next = nullptr;
    if(ls->n ==0)
    {
        ls->head = temp;
    }
    else{
        ls->tail->next= temp;
    }
    ls->tail = temp;
    ls->n++;
}
void display(List* ls)
{
    Element* temp = ls->head;
    cout<<"\tTotal of element : "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data<<" , ";
        temp = temp->next;
    }
    cout<<endl;
}

void findPosition(List* ls , int data)
{
    Element* temp = ls->head;
    int position = 0;

    while (temp != nullptr)
    {
        if(temp->data == data)
        {
            cout<<"The value is at position "<<position<<endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout<<"Not found"<<endl;
}

void remove(List* ls, int index)
{
    if(index < 0 || index >= ls->n)
    {
        cout<<"Invalid index"<<endl;
        return;
    }

    Element* temp = ls->head;

    if(index == 0)
    {
        ls->head = temp->next;
        if(ls->n == 1)
        {
            ls->tail = nullptr;
        }
        delete temp;
        ls->n--;
        return;
    }

    Element* previous = nullptr;
    int position = 0;

    while(temp != nullptr && position < index)
    {
        previous = temp;
        temp = temp->next;
        position++;
    }

    previous->next = temp->next;
    if(temp == ls->tail)
    {
        ls->tail = previous;
    }
    delete temp;
    ls->n--;
}
int main()
{
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;


    for(int i = 0;i < 5;i++)
    {
        cout<<"insert "<<i;
        cout<<endl;
        add(ls,i);
    }
    display(ls);
    findPosition(ls,3);

    return 0;
}

