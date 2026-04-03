#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element* next;
};
struct List{
    int n;//number of element
    Element* head;
    Element* tail;
};
