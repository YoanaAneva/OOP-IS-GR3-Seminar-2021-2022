#include <iostream>
using namespace std;

bool isTheAuthor(char *name, char *name1);

struct Book
{
    char title[40];
    char authorName[32];
    char genre[20];
    int ISBN;
    double price;

    void createBook()
    {
        cout << endl << "Enter book: " << endl;
        cin.ignore();
        cout << "Enter title: ";
        cin.getline(title, 64);
        cout << "Enter author: ";
        cin.getline(authorName, 64);
        cout << "Enter genre: ";
        cin.getline(genre, 64);
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter price: ";
        cin >> price;
    }

    void printBook()
    {
        cout << endl << title << endl;
        cout << authorName << endl;
        cout << genre << endl;
        cout << ISBN << endl;
        cout << price << endl;
    }
};

const int MAX_BOOKS = 100;
struct Bookstore
{
    int numberOfBooks;
    Book books[MAX_BOOKS];
};

void initializeBookStore(Bookstore& store)
{
    int count = store.numberOfBooks;
    for(int i = 0; i < count; i++)
    {
        store.books[i].createBook();
    }
}

void findISBN(Bookstore store, int ISBN)
{
    for(int i = 0; i < store.numberOfBooks; i++)
    {
        if(store.books[i].ISBN == ISBN)
        {
            cout << "Books with matching ISBN: " << endl;
            store.books[i].printBook();
        }
    }
}

void getAllBooksByAuthorName(Bookstore store, char* authorName)
{
    for(int i = 0; i < store.numberOfBooks; i++)
    {
        if(store.books[i].authorName[i] = authorName[i])
        {
            if(isTheAuthor(store.books[i].authorName, authorName))
                store.books[i].printBook();
        }
    }
}

void getAllBooksCheaperThan(Bookstore store, double price)
{
    for(int i = 0; i < store.numberOfBooks; i++)
    {
        if(store.books[i].price <= price)
            store.books[i].printBook();
    }
}


int main()
{
    Bookstore books;
    cout << "Enter number of books: ";
    cin >> books.numberOfBooks;
    initializeBookStore(books);

    // int ISBN;
    // cout << "Enter wanted ISBN: ";
    // cin >> ISBN;
    // findISBN(books, ISBN);

    // cout << "Enter author: ";
    // char authorName[30];
    // cin.ignore();
    // cin.getline(authorName, 30);
    // getAllBooksByAuthorName(books, authorName);

    cout << "Enter max price: ";
    double price;
    cin >> price;
    getAllBooksCheaperThan(books, price);

}

bool isTheAuthor(char *name, char *name1)
{
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(name[i] != name1[i])
            return false;
    }
    return true;
}