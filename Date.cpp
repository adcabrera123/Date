//
// Created by andrew on 5/20/17.
//

#include "Date.h"

/**
 * @brief Date::Date
 * initialized a date class to 1/1/1995
 */
Date::Date() {
    day = 01;
    month = 01;
    year = 1995;
}

/**
 * @brief Date::Date
 * @param m
 * @param d
 * @param y
 * initializes A Date class with the input parameters.  The
 * first sets day, second sets month, and third sets year
 */
Date::Date(int m, int d, int y) {
    day = d;
    month = m;
    year = y;
}

/**
 * @brief Date::Date
 * @param otherDate
 * copy constructor for Date class
 */
Date::Date(const Date &otherDate) {
    day = otherDate.getDay();
    month = otherDate.getMonth();
    year = otherDate.getYear();
}

/**
 * @brief Date::operator==
 * @param otherDate
 * @return
 * returns true if day, month, and year are equal to that of the
 * inputted Date class.  Returns false otherwise
 */
bool Date::operator==(const Date& otherDate) const {
    return (
        day == otherDate.getDay() &&
        month == otherDate.getMonth() &&
        year == otherDate.getYear()
    );
}

/**
 * @brief Date::operator!=
 * @param otherDate
 * @return
 * returns true if any of the Date instance variables are not
 * equal to that of the Date class inputted to the function
 */
bool Date::operator!=(const Date &otherDate) const {
    return day != otherDate.getDay() ||
           month != otherDate.getMonth() ||
           year != otherDate.getYear();
}

/**
 * @brief Date::operator>
 * @param otherDate
 * @return
 * returns true if the current date is later than the Date inputted to the
 * function.  It checks year, month, and day
 */
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

/**
 * @brief Date::operator>=
 * @param otherDate
 * @return
 * returns true if the current Date object has greater than or equal to
 * date than the date inputted to the class.  It calls the overloaded ==
 * to check for class equality and class the overloaded > to check to see
 * if the class is greater than the inputted class
 */
bool Date::operator>=(const Date &otherDate) const {
    bool isGreater = false;

    if (*this == otherDate)
        isGreater = true;
    else if(*this > otherDate)
        isGreater = true;

    return isGreater;
}

/**
 * 
 * @param otherDate
 * @return
 */
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

