#include <iostream>
#include "src/library.h"


int main() {
    Book b1 = {"Оно", "Стивен Кинг", true};
    Book b2 = {"Зеленая миля", "Стивен Кинг", true};
    Book b3 = {"Сияние", "Стивен Кинг", true};
    Book b4 = {"Мизери", "Стивен Кинг", true};
    Book b5 = {"Стихи", "Сола Монова", true};
 

    Library library = Library({&b1, &b2, &b3, &b4, &b5});
    library.printRange();

    Reader testAcc = Reader (1);

    Book *book = library.findBook((std::string) "Стивен Кинг", (std::string) "Оно");

    library.takeBook(testAcc, book);
    library.takeBook(testAcc, &b2);
    testAcc.printRange();

    library.returnBook(testAcc, &b1);
    testAcc.printRange();
    library.printRange();

    std::vector<const Book*> bookList = library.findBook("Стивен Кинг", false);
    for (int i = 0; i < bookList.size(); ++i) {
        std::cout << bookList[i]->name << std::endl;
    }
}
