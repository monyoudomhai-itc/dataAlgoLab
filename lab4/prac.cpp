#include <iostream>
using namespace std;

// struct Element {
//     int data;
//     Element* next;
// };
// struct List
// {
//     int n ;
//     Element* head;
//     Element* tail;
// };
// void function1(List* ls,int data)
// {
//     Element* e = new Element;
//     e->data =data;
//     e->next= ls->head;
//     ls->head = e;
//     if(ls->n ==0)
//     {
//         ls->tail = e;
//     }
//     ls->n ++;
// }
// int main()
// {
//     List* list1 = new List;
//     function1(list1 ,6);
//     function1(list1,9);
//     Element* e = list1->head;

//     while (e != nullptr)
//     {
//         cout<<"Number :"<<e->data<<endl;
//         e = e->next;
//     }
//     return 0;
// }

class Person{
    public: 
    int id;
    string name;
    void addPer(string name,int id)
    {
        this->id = id;
        this->name = name;
    }
};
class Element{
    public:
    Person data;
    Element* next;
};
class List{
    public:
    int n;//number of elements
    Element* head;
    Element* tail;
};
void add(List* ls,Person data)
{
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if(ls->n == 0)
    {
        ls->head =e ;
    } 
    else 
    {
        ls->tail->next =e;
    }
    ls->tail = e;
    ls->n += 1;
}
void display(List* ls)
{
    Element* temp  = ls->head;
    cout<<"Number of Element: "<<ls->n<<endl;
    while(temp != nullptr)
    {
        cout<<temp->data.id<<"\n";
        cout<<temp->data.name << "\n";
        temp = temp->next;
    }
}
int main()
{
    Person p;
    List* lists = new List;
    lists->n = 0;
    lists->head = nullptr;
    lists->tail = nullptr;
    p.addPer("dom",23);
    add(lists,p);
    Person p1;
    p1.addPer("Sorak" , 23);
    add(lists,p1);
    display(lists);
    return 0;
}