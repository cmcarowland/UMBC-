#ifndef MURACH_USEDBOOK_H
#define MURACH_USEDBOOK_H

#include <string>
#include "Book.h"

class UsedBook : public Book {

public:
    UsedBook(std::string name = "", double price = 0.0, 
         int disc_pct = 0, std::string author_param = "") :
         Book(name, price, disc_pct, author_param) {
    }

    std::string get_description() const override {
        return Book::get_description() + " (USED)";
    }
};
#endif // MURACH_BOOK_H
