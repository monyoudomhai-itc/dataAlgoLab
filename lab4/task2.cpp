#include <iostream> 
using namespace std;

struct Student
{
    int id;
    string name;
    int year;
    string degree;
    void addStudent(int id,string name,int year,string degree)
    {
        this->id = id;
        this->name = name;
        this->year= year;
        this->degree = degree;
    }
    /* data */
};
struct Element
{
    Student data;
    Element* next;
};
struct ListStudent
{
    int n;//number of all element
    Element* head;
    Element* tail;
    /* data */
};

