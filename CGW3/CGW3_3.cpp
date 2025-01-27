#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
struct Book {
    int udcNumber;                // ����� ���
    vector<string> authors;       // ������ ������� (���)
    string title;                 // ��������
    int year;                     // ��� �������
    // �������� ��������� ��� �������������� ���� �� ��������
    bool operator<(const Book& other) const {
        return title < other.title;
    }
};
// ������� ��� ���������� ������� �� ��������
void sortAuthors(vector<string>& authors) {
    sort(authors.begin(), authors.end(), [](const string& a, const string& b) {
        return a < b;
        });
}
// ������� ���������� �����
void add(set<Book>& library, const Book& newBook) {
    library.insert(newBook);
}
// ������� �������� ����� �� ��������
void remove(set<Book>& library, const string& title) {
    auto it = find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
        });
    if (it != library.end()) {
        library.erase(it);
        cout << "����� �������: " << title << endl;
    }
    else cout << "����� �� �������: " << title << endl;
}
// ������� ������ ����� �� ��������
void findTitle(const set<Book>& library, const string& title) {
    auto it = find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
        });
    if (it != library.end()) {
        cout << "������� �����:" << endl;
        cout << "���: " << it->udcNumber << endl;
        cout << "������: ";
        for (const auto& author : it->authors)
            cout << author << ", ";
        cout << endl;
        cout << "��������: " << it->title << endl;
        cout << "��� �������: " << it->year << endl << endl;
    }
    else cout << "����� �� �������: " << title << endl;
}
// ������� ������ ���� ������
void findAuthor(const set<Book>& library, const string& author) {
    cout << "����� ������ " << author << ":" << endl;
    for (const auto& book : library) {
        if (find(book.authors.begin(), book.authors.end(), author) != book.authors.end()) {
            cout << "���: " << book.udcNumber << endl;
            cout << "��������: " << book.title << endl;
            cout << "��� �������: " << book.year << endl << endl;
        }
    }
}
// ������� ���������� ������ � �����
void addAuthor(set<Book>& library, const string& title, const string& newAuthor) {
    auto it = find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
        });
    if (it != library.end()) {
        Book updatedBook = *it;
        library.erase(it);
        updatedBook.authors.push_back(newAuthor);
        sortAuthors(updatedBook.authors);
        library.insert(updatedBook);
        cout << "����� �������� � �����: " << title << endl;
    }
    else cout << "����� �� �������: " << title << endl;
}
// ������� �������� ������ �� �����
void removeAuthor(set<Book>& library, const string& title, const string& author) {
    auto it = find_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
        });
    if (it != library.end()) {
        Book updatedBook = *it;
        library.erase(it);
        updatedBook.authors.erase(remove(updatedBook.authors.begin(), updatedBook.authors.end(), author), updatedBook.authors.end());
        library.insert(updatedBook);
        cout << "����� ����� �� �����: " << title << endl;
    }
    else cout << "����� �� �������: " << title << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("books.txt");
    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� ����!" << endl;
        return 1;
    }
    if (inputFile.peek() == EOF) {
        cerr << "���� ����" << endl;
        return 1;
    }
    set<Book> library;
    string line;
    while (getline(inputFile, line)) {
        istringstream stream(line);
        Book book;
        string authorsLine;
        // ��������� ������ � �����
        stream >> book.udcNumber;        
        stream.ignore();                
        getline(stream, authorsLine, ';'); 
        getline(stream, book.title, ';');  
        stream >> book.year;             
        // ��������� ������ ������� �� ��������� ���
        istringstream authorsStream(authorsLine);
        string author;
        while (getline(authorsStream, author, ',')) {
            book.authors.push_back(author);
        }
        sortAuthors(book.authors);
        library.insert(book);
    }
    inputFile.close();
    // ������������ ������ �������
    cout << "������ ���� � ����������:" << endl;
    for (const auto& book : library) {
        cout << "���: " << book.udcNumber << endl;
        cout << "������: ";
        for (const auto& author : book.authors) {
            cout << author << ", ";
        }
        cout << endl;
        cout << "��������: " << book.title << endl;
        cout << "��� �������: " << book.year << endl << endl;
    }
    // ���������� �����
    Book newBook = { 99999, {"������� ���� ���������"}, "������� � ������ �����", 2023 };
    add(library, newBook);
    // �������� �����
    remove(library, "���������������");
    // ����� ����� �� ��������
    findTitle(library, "���������");
    // ����� ���� ������
    findAuthor(library, "������ ���� ��������");
    // ���������� ������ � �����
    addAuthor(library, "���� ������", "�������� ������ ���������");
    // �������� ������ �� �����
    removeAuthor(library, "���� ������", "������� ������ ���������");
    cout << "\n���������� ������ ���� � ����������:" << endl;
    for (const auto& book : library) {
        cout << "���: " << book.udcNumber << endl;
        cout << "������: ";
        for (const auto& author : book.authors) {
            cout << author << ", ";
        }
        cout << endl;
        cout << "��������: " << book.title << endl;
        cout << "��� �������: " << book.year << endl << endl;
    }
    return 0;
}