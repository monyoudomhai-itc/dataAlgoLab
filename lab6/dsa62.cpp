#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    /* data */
};
struct List
{
    int n;
    Node* head;
    Node* tail;
    /* data */
};
List* createEmptyList()
{
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void addBegin(List* ls,int data)
{
    Node* e = new Node;
    e->data = data;
    e->next = ls->head;
    e->prev = nullptr;
    if(ls->n == 0)
    {
        ls->tail = e;
    }
    ls->head = e;
    ls->n++;
}
void addLast(List* ls, int data){
    Node* e = new Node;
    e->data = data;
    e->next = nullptr;
    e->prev = ls->tail;
    if(ls->n==0)
    {
        ls->head = e;
    }
    else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}
void addAtPosition(List* ls,int data,int pos)
{
    if(!ls || pos < 0 || pos < ls->n)
    {
        cout<<"Invalid position"<<endl;
        return ;
    }
    if(ls->n ==0){
        addBegin(ls,data);
    }
    if(ls->n == pos)
    {
        addLast(ls,data);
    }
    Node* current = nullptr;
    if(pos >= ls->n /2)
    {
        //start from the tail is the faster than head
        current = ls->tail;
        for(int i = ls->n ; i > pos ;i--)
        {
            current = current->prev;
        }
    }
    else{
        current = ls->head;
        for(int i = 0;i< pos -1 ;i++)
        {
            current = current->next;
        }
    }
    Node* e = new Node;
    e->data = data;
    e->next = current->next;
    e->prev = current;

    current->next->prev = e;
    current->next = e;
    ls->n++;
    
}
void display(List* ls)
{
    Node* e = ls->head;
    while(e != nullptr)
    {
        cout<<e->data<<" ";
        e = e->next;
    }
    cout<<endl;
}
void computeStats(List* ls)
{
    if(!ls->head)
    {
        cout << "List is empty." << endl;
        return;
    }
    int sum = 0;
    Node* e = ls->head;
    while(e != nullptr)
    {
        sum += e->data;
        e = e->next;
    }
    double average = (double)sum / ls->n;
    cout << "Sum     : " << sum     << endl;
    cout << "Average : " << average << endl;
}
void deleteBegin(List* ls){
    if(ls->n == 0)
    {
        return ;
    }
    Node* e = ls->head;
    ls->head = e->next;
    if(ls->head != nullptr)
    {
        ls->head->prev = nullptr;
    }
    else {
        ls->tail = nullptr;
    }
    delete e;
    ls->n--;
}
void deleteLast(List* ls){
    if(ls->n ==0) return ;
    Node* e = ls->tail;
    ls->tail = e->prev;
    if(ls->tail != nullptr) ls->tail->next = nullptr;
    else ls->head = nullptr;
    delete e;
    ls->n --;
}
void deletePos(List* ls, int pos)
{
    if(pos < 0 || pos >= ls->n)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 0)       { deleteBegin(ls); return; }
    if(pos == ls->n-1) { deleteLast(ls);  return; }

    // find node at pos
    Node* current = nullptr;
    if(pos <= ls->n / 2)
    {
        current = ls->head;
        for(int i = 0; i < pos; i++)
            current = current->next;
    }
    else
    {
        current = ls->tail;
        for(int i = ls->n - 1; i > pos; i--)
            current = current->prev;  
    }

    // unlink and delete
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    ls->n--;
}
void findMin(List* ls)
{
    Node* e = ls->head;
    int min = e->data;
    while (e!= nullptr)
    {
        if(e->data < min) min = e->data;
        e =e->next;
    }
    cout<<"Minimum is the List is : "<<min<<endl;
}
void findMax(List* ls)
{
    Node* e = ls->head;
    int max = e->data;
    while (e!= nullptr)
    {
        if(e->data > max) max = e->data;
        e =e->next;
    }
    cout<<"Maximum is the List is : "<<max<<endl;
}
int main()
{
    List* ls = createEmptyList();

    cout<<"now Adding 1 ,2,3,4,5 at the end"<<endl;
    for(int i = 1;i< 6;i++)
    {
        addLast(ls,i);
    }
    display(ls);
    findMin(ls);
    findMax(ls);
    return 0;
}
// exercise 2
// int main()
// {
//     srand(time(0));

//     List* ls = createEmptyList();

//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     for(int i = 0; i < n; i++)
//     {
//         int randNum = rand() % 100 + 1;  // range 1 - 100
//         addLast(ls, randNum);
//     }

//     display(ls);
//     computeStats(ls);
//     return 0;
// }