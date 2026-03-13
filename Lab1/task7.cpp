#include <iostream>
#include <string>
using namespace std;

// Define Book structure
struct Book {
    int id;
    string isbn;
    string title;
    int year;
    string authors[5];   // allow up to 5 authors
    int authorCount;
    float price;
};

// Function to display a book by ISBN
void displayBookByISBN(Book books[], int size, string isbn) {
    bool found = false;

    for(int i = 0; i < size; i++) {
        if(books[i].isbn == isbn) {
            cout << "Book ID: " << books[i].id << endl;
            cout << "ISBN: " << books[i].isbn << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Published Year: " << books[i].year << endl;

            cout << "Authors: ";
            for(int j = 0; j < books[i].authorCount; j++) {
                cout << books[i].authors[j];
                if(j < books[i].authorCount - 1) cout << ", ";
            }
            cout << endl;

            cout << "Price: $" << books[i].price << endl;
            cout << "----------------------" << endl;

            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }
}

// Function to display all books
void displayAllBooks(Book books[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "Book ID: " << books[i].id << endl;
        cout << "ISBN: " << books[i].isbn << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Published Year: " << books[i].year << endl;

        cout << "Authors: ";
        for(int j = 0; j < books[i].authorCount; j++) {
            cout << books[i].authors[j];
            if(j < books[i].authorCount - 1) cout << ", ";
        }
        cout << endl;

        cout << "Price: $" << books[i].price << endl;
        cout << "----------------------" << endl;
    }
}

int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // Input book data
    for(int i = 0; i < SIZE; i++) {
        cout << "Enter info for book " << i + 1 << endl;

        cout << "ID: ";
        cin >> books[i].id;

        cout << "ISBN: ";
        cin >> books[i].isbn;

        cin.ignore();

        cout << "Title: ";
        getline(cin, books[i].title);

        cout << "Published Year: ";
        cin >> books[i].year;

        cout << "Number of Authors: ";
        cin >> books[i].authorCount;

        cin.ignore();
        for(int j = 0; j < books[i].authorCount; j++) {
            cout << "Author " << j + 1 << ": ";
            getline(cin, books[i].authors[j]);
        }

        cout << "Price: ";
        cin >> books[i].price;

        cout << "----------------------" << endl;
    }

    cout << "\nAll Books:\n";
    displayAllBooks(books, SIZE);

    string searchISBN;
    cout << "\nEnter ISBN to search: ";
    cin >> searchISBN;

    displayBookByISBN(books, SIZE, searchISBN);

    return 0;
}