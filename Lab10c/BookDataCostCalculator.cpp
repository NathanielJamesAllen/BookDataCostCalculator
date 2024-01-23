#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct book {
    string title;
    string author;
    int year;
    int pages;
    float cost;
};
void printLine(book);
void printFinal(int, float);

book myBook;
ifstream inFile;
ofstream outFile;
int bookCount;
float LibraryValue;

int main()
{
    int i, num_books;
    bookCount = 0;
    LibraryValue = 0;

    inFile.open("bookdata-fmt2.txt");
    outFile.open("bookdata-fmt3.txt");
    inFile >> num_books;
    inFile.ignore(256, '\n');

    for (i = 0; i < num_books; i++) {

        getline(inFile, myBook.title);
        getline(inFile, myBook.author);
        inFile >> myBook.year >> myBook.pages >> myBook.cost;
        inFile.ignore(256, '\n');

        bookCount++;
        LibraryValue = LibraryValue + myBook.cost;

        printLine(myBook);
    }

    inFile.close();
    outFile.close();

    outFile.open("bookdata-fmt3.txt");
    
    printFinal(bookCount, LibraryValue);
}
void printLine(book x) {
    outFile << "The title is       : " << x.title << endl;
    outFile << "The author is      : " << x.author << endl;
    outFile << "The year is        : " << x.year << endl;
    outFile << "The number of pages: " << x.pages << endl;
    outFile << fixed << showpoint << setprecision(2);
    outFile << "The cost is        : " << x.cost << endl;
    outFile << endl;

}

void printFinal(int c, float v) {
    outFile << endl;
    outFile << "Number of Books: " << c << endl;
    outFile << fixed << showpoint << setprecision(2) << endl;
    outFile << "The total cost :$ " << v << endl;

}