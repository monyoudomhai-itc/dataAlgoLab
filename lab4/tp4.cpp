#include <iostream>
using namespace std;

// struct Element
// {
//     int data;
//     Element* next;
//     /* data */
// };
// struct List
// {
//     int n;
//     Element* head;
//     Element* tail;
//     /* data */
// };
// List* createListEmpty()
// {
//     List* ls =  new List;
//     ls->head=nullptr;
//     ls->tail=nullptr;
//     ls->n = 0;
//     return ls;
// }
// void add(List* ls ,int data)
// {
//     Element* e = new Element;
//     e->data = data;
//     e->next = nullptr;
//     if(ls->n == 0 )
//     {
//         ls->head = e;
//     }
//     else{
//         ls->tail->next = e;
//     }
//     ls->tail = e;
//     ls->n++;
// }
// void display(List* ls)
// {
//     int result = 0;
//     Element* e = ls->head;
//     cout<<"Total All element : "<<ls->n<<endl;
//     cout<<"All data in the List are : ";
//     while(e != nullptr)
//     {
//         cout<<e->data << " ";
//         result += e->data;
//         e = e->next;
//     }
//     cout<<endl;
//     cout<<"Summation of all number is : "<<result<<endl;
// }
// int main()
// {
//     List* ls = createListEmpty();
//     cout<<"*** A program to store number as many as possible ***"<<endl;
//     int isZero = 0 ;
//     int data;
//     while (true)
//     {
//         cout<<"Enter a number: ";
//         cin>>data;
//         add(ls,data);
//         if(data == 0)
//         {
//             isZero ++;
//         }
//         if(isZero == 1)
//         {
//             cout<<"You have entered the number 0 once only 1 left program will stop."<<endl;

//         }
//         else if(isZero == 2) 
//         {
//             cout<<"You have entered the number 0 twice the program going to stop now."<<endl;
//             break;
//         }
//         /* code */
//     }
//     display(ls);
//     return 0;
// }
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
List* createEmpty()
{
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void add(List* ls, int data)
{
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if(ls->n==0)
    {
        ls->head = e;
    }
    else{
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n ++;
}
void display(List* ls)
{
    Element* e = ls->head;
    cout<<"Total of all element :"<<ls->n<<endl;
    while (e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
        /* code */
    }
    cout<<endl;
}

int main()
{
    List* ls = createEmpty();
    for(int i = 0;i<5;i++)
    {
        add(ls,i);
    }
    display(ls);
    return 0;
}

