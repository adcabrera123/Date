#include <iostream>
#include "Date.h"

int main() {
    Date date(01, 01, 1995);

    for (int i = 0; i < 365; ++i) {
        std::cout << date;
        date++;
    }
    std::cout << date;

    return 0;
}

std::ostream& operator<<(std::ostream& out, Date &date) {
    out << date.month << "/" << date.day << "/" << date.year << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Date &date) {
    in >> date.month >> date.day >> date.year;

    return in;
}