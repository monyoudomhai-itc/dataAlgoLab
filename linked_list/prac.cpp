#include <iostream>
using namespace std;

struct  Element
{
    int data;
    Element* next;
    /* data */
};
struct  List
{
    int n;
    Element* head;
    Element* tail;
    void addLastNumber(List* ls,int data)
    {
        Element* e = new Element;
        e->data = data;
        ls->tail = nullptr;
    }
    /* data */
};


