#include<iostream>
using namespace std;

struct Product
{
    int id;
    string name;
    int price;
    Product()
    {

    }
    Product(int id,string name,int price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    /* data */
};
struct Element
{
    Product data;
    Element* next;
    /* data */
};
struct ListProduct
{
    int n;
    Element* head;
    Element* tail;
    /* data */
};
ListProduct* createEmptyList()
{
    ListProduct* ls = new ListProduct;
    ls->n=0;
    ls->tail=nullptr;
    ls->head=nullptr;
    return ls;
}
void addProductToBegin(ListProduct* ls,Product data)
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
void addProductToEnd(ListProduct* ls,Product data)
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
void display(ListProduct* ls)
{
    Element* e = ls->head;
    cout<<"total element "<<ls->n<<" : "<<endl;
    int count = 1;
    while (e != nullptr)
    {
        cout<<"Product #"<<count<<endl;
        cout<<"id: "<<e->data.id<<endl;
        cout<<"Name: "<<e->data.name<<endl;
        cout<<"price: $"<<e->data.price<<endl;
        cout<<endl;
        count++;
        e = e->next;
        /* code */
    }
    
}
int main()
{
    ListProduct* ls = createEmptyList();
    for (int i = 0; i < 10; i++) {
    float price = rand() % 100; // 0 - 99
    Product p(i + 1, "P" + to_string(i + 1), price);

    if (price < 50) {
        addProductToBegin(ls, p);
    } else {
        addProductToEnd(ls, p);
    }
    }
    display(ls);
    return 0;
}