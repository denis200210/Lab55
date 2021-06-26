
#include <vector>
#include <string>
#include <set>

struct Book {
    std::string name;
    std::string author;
    bool stock;
    bool operator !=(const Book &book);
};

class Reader {
private:
    uint32_t id;
    std::vector<Book*> readerBooks;

public:
    explicit Reader(uint32_t id);
    void addBook(Book *book);
    void removeBook(Book *book);
    void printRange();
};

class Library {
private:
    std::vector<Book*> libBooks;

public:
    explicit Library (const std::vector<Book*> &books);
    void addBook(Book *bookLink);
    Book* findBook(const std::string &author, const std::string &name);
    std::vector<const Book*> findBook(const std::string &desired, bool isName);
    void takeBook(Reader &reader, Book *book);
    void returnBook(Reader &reader, Book *book);
    void printRange();
};




