#include <iostream>
using namespace std;

// task 1 
// struct Element{
//     int data;
//     Element* next;
// };
// struct List{
//     int n;//number of element
//     Element* head;
//     Element* tail;
// };

//task2
// struct  Student 
// {
//     int id,year;
//     string name,degree;
    
//     /* data */
// };
// struct Element
// {
//     Student data;
//     Element* next;
//     /* data */
// };

// struct ListStudent
// {
//     int n;
//     Element* head;
//     Element* tail;
//     /* data */
// };
// ListStudent* createEmptyList(){
//     ListStudent* ls = new ListStudent;
//     ls->n = 0;
//     ls->head = nullptr;
//     ls->tail = nullptr;
//     return ls;
// };
// void add(Student s , ListStudent* ls)
// {
//     Element* temp = new Element;
//     temp->data = s;
//     ls->tail = nullptr;
//     if(ls->n == 0)
//     {
//         ls->head = temp;
//     }
//     else {
//         ls->tail->next = temp;
//     }
//     ls->tail = temp;
//     ls->n++;
// }
// void display(ListStudent* ls)
// {
//     Element* e = ls->head;
//     while(e != nullptr)
//     {
//         cout<<"Name :"<<e->data.name<<endl;
//         e = e->next;
//     }
// }
// int main()
// {
//     ListStudent* ls = createEmptyList();
//     Student s[5] ;
//     s[0].name = " dom ";
//     s[1].name = "Ratana";
//     add(s[0],ls);
//     add(s[1],ls);

//     display(ls);

//     return 0;
// }

// task5 
struct Element
{
    int data;
    Element* next;
    /* data */
};
// struct ListNumber
// {
//     int n;
//     Element* head;
//     Element* tail;
//     /* data */
//     void addNumber(ListNumber* ls,int data)
//     {
//         Element* e = new Element;
//         e->data = data;
//         e->next = nullptr;
//         if(ls->n == 0)
//         {
//             ls->head = e;
//         }
//         else {
//             ls->tail->next = e;
//         }
//         ls->tail = e;
//         ls->n++;
//     }
//     void display(ListNumber* ls)
//     {
//         Element* e = ls->head;
//         cout<<"Total of all elements "<<ls->n<< " : ";
        
//         while(e != nullptr)
//         {
//             cout<<e->data<<" ,";
//             e = e->next;
//         }
//         cout<<endl;
//     }
//     int sum(ListNumber* ls)
//     {
//         Element* e = ls->head;
//         int result=0;
//         while(e != nullptr)
//         {
//             result += e->data;
//             e = e->next;
//         }
//         return result;
//     }
// };
struct ListNumber
{
    int n;
    Element* head;
    Element* tail;
    void add(ListNumber* ls ,int data)
    {
        Element* e = new Element;
        e->data = data;
        e->next = ls->head;
        if(ls->n == 0)
        {
            ls->tail = e;
        }
        ls->head = e;
        ls->n++;
    }
    void addNumber(ListNumber* ls,int data)
    {
        Element* e = new Element;
        e->data = data;
        e->next = nullptr;
        if(ls->n == 0){
            ls->head = e;
        }
        else {
            ls->tail->next = e;
        }
        ls->tail = e;
        ls->n++;
    }
    void display(ListNumber* ls)
    {
        Element* e = ls->head;
        cout<<"Total of all element "<<ls->n<<" : ";
        while(e != nullptr)
        {
            cout<<e->data << "  ";
            e = e->next; 
        }
    }
    int sum(ListNumber* ls)
    {
        Element* e = ls->head;
        int result = 0;
        while(e != nullptr)
        {
            result += e->data;
            e = e->next;
        }
        return result;
    }
    /* data */
};

ListNumber* createEmpty()
{
    ListNumber* ls = new ListNumber;
    ls->n=0;
    ls->head=nullptr;
    ls->tail = nullptr;
    return ls;
}
int main ()
{
    ListNumber* ls = createEmpty();
    int isZero =0;
    int data;
    cout<<"***A program to store numbers aas many as possible***"<<endl;
    while(isZero != 2)
    {
        cout<<"Enter a number : ";
        cin>>data;
        // ls->addNumber(ls,data);
        ls->add(ls,data);
        if(data == 0)
        {
            isZero ++;
        }
        if(isZero == 1)
        {
            cout<<"you hvaed enter number 0 once ,only 1 more left."<<endl;
            cout<<"\t We will quit the program"<<endl;
        }
        else if(isZero == 2)
        {
            cout<<"you have entered the number 0 twice so far."<<endl;
            cout<<"The program is going to stop now ..."<<endl;
        }
    }
    cout<<endl;
    ls->display(ls);
    cout<<endl;
    cout<<"Summation of all element : "<<ls->sum(ls)<<endl;
}


