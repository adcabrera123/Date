#include <iostream>
#include "Date.h"
/**
 *
 * @brief operator<<
 * @param out
 * @param date
 * @return
 * returns an ostream reference with an output of month/day/year format
 */
std::ostream& operator<<(std::ostream& out, Date &date) {
    out << date.month << "/" << date.day << "/" << date.year << std::endl;
    return out;
}

/**
 *
 * @brief operator>>
 * @param in
 * @param date
 * @return
 *returns an istream reference that takes in a month day and year
 */
std::istream& operator>>(std::istream& in, Date &date) {
    in >> date.month >> date.day >> date.year;

    return in;
}