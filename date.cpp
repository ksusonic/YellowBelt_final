#include "date.h"

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date::Date(int new_year, int new_month, int new_day)
        : year(new_year), month(new_month), day(new_day) {}

ostream &operator<<(ostream &os, const Date &date) {
    os << setw(4) << setfill('0') << date.GetYear() <<
       '-' << setw(2) << setfill('0') << date.GetMonth() <<
       '-' << setw(2) << setfill('0') << date.GetDay();
    return os;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
