//
// Created by andrew on 5/20/17.
//

#ifndef DATEOVERLOADED_DATE_H
#define DATEOVERLOADED_DATE_H

#include <iostream>

class Date {
    friend std::ostream& operator<<(std::ostream& out, Date& date);
    friend std::istream&operator>>(std::istream&, Date&);
public:
    Date();

    Date(int d, int m, int y);

    Date(const Date& otherDate);

    bool operator==(const Date& otherDate) const;

    bool operator!=(const Date& otherDate) const;

    bool operator>(const Date& otherDate) const;

    bool operator>=(const Date& otherDate) const;

    bool operator<(const Date& otherDate) const;

    bool operator<=(const Date& otherDate) const;

    Date operator++();

    Date operator++(int u);

    std::string monthType();

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    void print() const;

    ~Date();

private:
    int day;
    int month;
    int year;
};


#endif //DATEOVERLOADED_DATE_H
