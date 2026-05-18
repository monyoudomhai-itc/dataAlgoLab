#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
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
void searchByName(ListProduct* ls,string targetName)
{
    bool found = true;
    Element* e = ls->head;
    while(e != nullptr)
    {
        if(e->data.name == targetName)
        {
            cout<<"id: "<<e->data.id<<endl;
            cout<<"Name: "<<e->data.name<<endl;
            cout<<"price: $"<<e->data.price<<endl;
            cout<<endl;
            found = false;
        }
        e = e->next;
    }
    if(found){
    cout<<"Product not found"<<endl;
    }
}
void searchByPrice(ListProduct* ls, int targetPrice)
{
    bool found = true;
    Element* e = ls->head;
    while(e != nullptr)
    {
        if(e->data.price == targetPrice)
        {
            cout<<"id: "<<e->data.id<<endl;
            cout<<"Name: "<<e->data.name<<endl;
            cout<<"price: $"<<e->data.price<<endl;
            cout<<endl;
            found = false;
        }
        e = e->next;
    }
    if(found){
    cout<<"Product not found"<<endl;
    }
}
void updateByProductId(ListProduct* ls, int targetId, string newName, int newPrice)
{
    Element* e = ls->head;
    while(e != nullptr)
    {
        if(e->data.id == targetId)
        {
            e->data.name = newName;
            e->data.price = newPrice;
            cout<<"Product updated successfully!"<<endl;
            return;
        }
        e = e->next;
    }
    cout<<"Product not found"<<endl;
}
int main()
{

    ListProduct* ls = createEmptyList();
    
    addProductToBegin(ls, Product(1, "Pen", 20));
    addProductToBegin(ls, Product(2, "Notebook", 35));
    addProductToBegin(ls, Product(3, "Eraser", 10));
    addProductToBegin(ls, Product(4, "Pencil", 45));
    addProductToBegin(ls, Product(5, "Ruler", 5));

    addProductToEnd(ls, Product(6, "Backpack", 60));
    addProductToEnd(ls, Product(7, "Calculator", 75));
    addProductToEnd(ls, Product(8, "Headphones", 90));
    addProductToEnd(ls, Product(9, "Water Bottle", 55));
    addProductToEnd(ls, Product(10, "Desk Lamp", 80));
    int choice;
    while(true)
    {
        cout<<"\n===== PRODUCT MENU ====="<<endl;
        cout<<"1. Display all products"<<endl;
        cout<<"2. Add product"<<endl;
        cout<<"3. Update product by ID"<<endl;
        cout<<"4. Search by Name"<<endl;
        cout<<"5. Search by Price"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        if(choice == 1)
        {
            display(ls);
        }
        else if(choice == 2)
        {
            int id, price, position;
            string name;
            cout<<"Enter product id: ";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter product name: ";
            getline(cin, name);
            cout<<"Enter product price: ";
            cin>>price;
            cout<<"Add to 1. Begin or 2. End: ";
            cin>>position;

            Product p(id, name, price);
            if(position == 1)
            {
                addProductToBegin(ls, p);
            }
            else
            {
                addProductToEnd(ls, p);
            }
            cout<<"Product added successfully!"<<endl;
        }
        else if(choice == 3)
        {
            int id, price;
            string name;
            cout<<"Enter product id to update: ";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter new product name: ";
            getline(cin, name);
            cout<<"Enter new product price: ";
            cin>>price;
            updateByProductId(ls, id, name, price);
        }
        else if(choice == 4)
        {
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter product name: ";
            getline(cin, name);
            searchByName(ls, name);
        }
        else if(choice == 5)
        {
            int price;
            cout<<"Enter product price: ";
            cin>>price;
            searchByPrice(ls, price);
        }
        else if(choice == 6)
        {
            cout<<"Goodbye!"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid choice!"<<endl;
        }
    }
    
    return 0;
}