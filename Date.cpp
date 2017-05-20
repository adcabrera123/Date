//
// Created by andrew on 5/20/17.
//

#include "Date.h"

Date::Date() {
    day = 01;
    month = 01;
    year = 1995;
}

Date::Date(int m, int d, int y) {
    day = d;
    month = m;
    year = y;
}

Date::Date(const Date &otherDate) {
    day = otherDate.getDay();
    month = otherDate.getMonth();
    year = otherDate.getYear();
}

bool Date::operator==(const Date& otherDate) const {
    return (
        day == otherDate.getDay() &&
        month == otherDate.getMonth() &&
        year == otherDate.getYear()
    );
}

bool Date::operator!=(const Date &otherDate) const {
    return day != otherDate.getDay() ||
           month != otherDate.getMonth() ||
           year != otherDate.getYear();
}

bool Date::operator>(const Date &otherDate) const {
    bool isGreater = false;

    if (year > otherDate.getYear())
        isGreater = true;
    else if (year == otherDate.getYear()) {
        if (month > otherDate.getMonth())
            isGreater = true;
    } else if (year == otherDate.getYear() &&
            month == otherDate.getMonth()) {
        if (day > otherDate.getDay())
            isGreater = true;
    }

    return isGreater;
}

bool Date::operator>=(const Date &otherDate) const {
    bool isGreater = false;

    if (*this == otherDate)
        isGreater = true;
    else if(*this > otherDate)
        isGreater = true;

    return isGreater;
}

bool Date::operator<(const Date &otherDate) const {
    bool isLessThan = false;

    if (year < otherDate.getYear())
        isLessThan = true;
    else if (year == otherDate.getYear())
    {
        if (month < otherDate.getMonth())
            isLessThan = true;
    } else if (year == otherDate.getYear() &&
               month == otherDate.getMonth()) {
        if (day < otherDate.getDay())
            isLessThan = true;
    }

    return isLessThan;
}

bool Date::operator<=(const Date &otherDate) const {
    bool isLessThan = false;

    if (*this == otherDate)
        isLessThan = true;
    else if (*this < otherDate)
        isLessThan = true;

    return isLessThan;
}

Date Date::operator++() {
    if (monthType() == "31Days")
    {
        if (month == 12 && day == 31)
        {
            month = 01;
            day = 01;
            year++;
        } else if (day == 31) {
            day = 01;
            month++;
        } else {
            day++;
        }
    } else if (monthType() == "30Days") {
        if (day == 30)
        {
            day = 01;
            month++;
        } else
            day++;
    } else  if (monthType() == "february"){
        if (day == 28)
        {
            day = 01;
            month++;
        } else
            day++;
    } else
        std::cout << "increment error!";

}

Date Date::operator++(int u) {
    Date date = *this;

    ++*this;

    return date;
}

std::string Date::monthType() {
    int monthWith31Days[] = {1, 3, 5, 7, 8, 10, 12};
    int monthWith30days[] = {4, 6, 9, 11};
    bool dayWith31Days = false;
    bool dayWith30Days = false;
    std::string monthType = "february";

    for (auto &&monthWith31Day : monthWith31Days) {
        if (month == monthWith31Day)
            dayWith31Days = true;
    }

    if (!dayWith31Days)
    {
        for (auto &&monthWith30day : monthWith30days) {
            if (month == monthWith30day)
                dayWith30Days = true;
        }
    }

    if (dayWith30Days)
        monthType = "30Days";
    else if (dayWith31Days)
        monthType = "31Days";

    return monthType;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

void Date::print() const {
    std::cout << month << "/" << day << "/"  << year << std::endl;
}

Date::~Date() {

}

