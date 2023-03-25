#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    int year;
    int pages;
public:
    Book(string title, string author, string publisher, int year, int pages) {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->year = year;
        this->pages = pages;
    }
    friend class Library;
};

class Library {
private:
    vector<Book*> books;
public:
    void addBook(string title, string author, string publisher, int year, int pages) {
        Book* book = new Book(title, author, publisher, year, pages);
        books.push_back(book);
    }
    void deleteBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->title == title) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }
    void displayBooks() {
        cout << "Library Books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << "Title: " << books[i]->title << endl;
            cout << "Author: " << books[i]->author << endl;
            cout << "Publisher: " << books[i]->publisher << endl;
            cout << "Year: " << books[i]->year << endl;
            cout << "Pages: " << books[i]->pages << endl;
            cout << endl;
        }
    }
};

int main() {
    Library library;
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925, 180);
    library.addBook("To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.", 1960, 281);
    library.addBook("1984", "George Orwell", "Secker and Warburg", 1949, 328);
    library.displayBooks();
    library.deleteBook("To Kill a Mockingbird");
    library.displayBooks();
    return 0;
}
