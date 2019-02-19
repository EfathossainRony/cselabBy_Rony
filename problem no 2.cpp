#include <bits/stdc++.h>

using namespace std;

class Book;

class Person{
public:
    string name;
    Person(){
    }
    Person(string name){
        this->name = name;
    }
};

class Customer: public Person{


public:
    Customer(string name): Person(name){
    }
    void display(){
        cout << "Name: " << name << endl;
    }

    friend void buyingDetail(Customer customer, Book book);
};

class Author{
    string name;

public:
    Author(){
    }

    Author(string name){
        this->name = name;
    }

    string put_name(){
        return name;
    }
};

class Category{
    string name;

public:
    Category(){
    }

    Category(string name){
        this->name = name;
    }

    string put_name(){
        return name;
    }
};

class Book{
    public:            ///book details
    string title;
    string category;
    string author;
    double price;
    string edition_no;


    Book(){
    }

    Book(string title, Category c, Author w, double price, string edition_no){
        this->title = title;
        this->category = c.put_name();
        this->author = w.put_name();
        this->price = price;
        this->edition_no = edition_no;

    }

    void display(){
        cout << "Book Title:" << title << endl;
        cout << "Category:  " << category << endl;
        cout << "Author:    " << author << endl;
        cout << "Price:     " << price << endl;
        cout << "Edition:   " << edition_no << endl;
    }

    friend void buingDetail(Customer customer, Book book);


};



void buyingDetail(Customer customer, Book book){ ///friend function
    double dis_price;

    if (book.price >= 300){
        dis_price = book.price - (book.price*10)/100;
    }
    else {
        dis_price = book.price;
    }

    cout << customer.name << " has brought " << book.title << " at price(with discount if it has) " << dis_price << endl;
    cout << "Book: " <<endl;
    book.display();


}

int main(){


    Author author1("Humayon Ahmed ");
    Author author2("Rabindro Nath");
    Author author3("Sukumar Roy");

    Category category1("Science Fiction");
    Category category2("Literature");

    Book book1("Tomader Jonno", category1, author1, 200.00, "sc100");
    Book book2("Deyal", category2, author1, 400.00, "lt273");
    Book book3("Abol Tabol", category2, author3, 150.00, "lt273");
    Book book4("Gitanjoli", category2, author2, 160.00, "lt273");
    Book book5("Chokher bali", category2, author2, 230.00, "lt273");


    cout <<endl<<"           Books Information: " << endl<<endl;
    cout<<"Enter book no to display,\n0 for break"<<endl;
    while(1)
    {
        int xz;
        cin>>xz;
        if(xz==1)
        {
          book1.display();
        }
        else if(xz==2)
        {
          book2.display();
        }
        else if(xz==3)
        {
          book1.display();
        }
        else if(xz==3)
        {
          book1.display();
        }
        else if(xz==4)
        {
          book4.display();
        }
        else break;
    }

    cout <<endl<<endl<< "           Customers: " << endl;
    Customer customer1("aditto");
    customer1.display();
    Customer customer2("shuvro");
    customer2.display();
    Customer customer3("adi");
    customer3.display();

    cout <<endl<< "Buying details: " << endl;
    buyingDetail(customer1, book2);
    cout <<endl<< "Buying details: " << endl;
    buyingDetail(customer2, book1);

}
