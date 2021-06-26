
#include <iostream>
#include "library.h"

bool Book::operator !=(const Book &book) {
    return (this->author != book.author) || (this->name != book.name);

}

Reader::Reader (uint32_t id) {
    this->id = id;
}

void Reader::addBook(Book *book) {
    readerBooks.push_back(book);
}

void Reader::removeBook(Book *book) {
    for (int i = 0; i < readerBooks.size(); ++i) {
        if (readerBooks[i] == book) {
            readerBooks.erase(readerBooks.begin() + i);
            return;
        }
    }
}

void Reader::printRange() {
    for (int i = 0; i < readerBooks.size(); ++i) {
        std::cout << readerBooks[i]->author << " - "
                  << readerBooks[i]->name << std::endl;
    }

    std::cout << std::endl;
}


Library::Library(const std::vector<Book*> &books) {
    this->libBooks = books;
}

void Library::addBook(Book *bookLink) {
    libBooks.push_back(bookLink);
}

Book* Library::findBook(const std::string &author, const std::string &name) {
    for (int i = 0; i < libBooks.size(); ++i) {
        if ((libBooks[i]->name == name) && (libBooks[i]->author == author)) {
            return libBooks[i];
        }
    }

    return nullptr;
}

std::vector<const Book*> Library::findBook(const std::string &desired, bool isName) {
    std::vector<const Book*> foundBook;
    if (isName){
        for (int i = 0; i < libBooks.size(); ++i) {
            if (libBooks[i]->name == desired) {
                foundBook.push_back(libBooks[i]);
            }
        }
    } else {
        for (int i = 0; i < libBooks.size(); ++i) {
            if (libBooks[i]->author == desired) {
                foundBook.push_back(libBooks[i]);
            }
        }
    }

    return foundBook;
}

void Library::takeBook(Reader &reader, Book *book) {
    book->stock = false;
    reader.addBook(book);
}

void Library::returnBook(Reader &reader, Book *book) {
    book->stock = true;
    reader.removeBook(book);
}

void Library::printRange(){
    for (int i = 0; i < libBooks.size(); ++i) {
        std::cout << libBooks[i]->author << " - "
                  << libBooks[i]->name << " - "
                  << (libBooks[i]->stock ? "(В наличии)" : "(Нет в наличии)") << std::endl;
    }

    std::cout << std::endl;
}
