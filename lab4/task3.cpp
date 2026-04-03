#include <iostream>
using namespace std;

struct Student{
    int id,year;
    string name,degree;
    void addStu(int id,string name,int year,string degree)
    {
        this->id=id;
        this->name = name;
        this->year= year;
        this->degree= degree;
    }
};
struct Element{
    Student data;
    Element* next;
};
struct ListStu{
    int n;//number of element
    Element* head;
    Element* tail;
    //task3
    void add(ListStu* ls , Student data)
    {
        Element* e = new Element;
        e->data = data;
        e->next = nullptr;
        if(ls->n == 0){ls->head = e;}
        else 
        {
            ls->tail->next = e;
        }
        ls->tail = e;
        ls->n++;
    }
    
};

ListStu* createEmptyList()
{
    ListStu* ls = new ListStu;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
int main()
{
    ListStu* ls = createEmptyList();
    Student s[5] ;
    s[0].addStu(12,"Dom",2023,"se");
    s[1].addStu(13,"Nana",2010,"AI");
    s[2].addStu(24,"Sorak",2040,"WEB");
    s[3].addStu(19,"Hong",2300,"SE");
    s[4].addStu(9,"Rual",2030,"AI");

    for (int i = 0;i < 5;i++)
    {
        ls->add(ls,s[i]);
    }
   
    return 0;
}