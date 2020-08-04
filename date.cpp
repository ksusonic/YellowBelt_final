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

string Date::GetString() const {
    stringstream ss;
    ss << *this;
    return ss.str();
}

ostream &operator<<(ostream &os, const Date &date) {
    os << setw(4) << setfill('0') << date.GetYear() <<
       '-' << setfill('0') << setw(2) << date.GetMonth() <<
       '-' << setfill('0') << setw(2) << date.GetDay();
    return os;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator<=(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <=
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator>(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator>=(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >=
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator==(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
bool operator!=(const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) !=
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

Date ParseDate(istream &in) {
    int year, month, day;
    in >> year;
    in.ignore();
    in >> month;
    in.ignore();
    in >> day;
    return Date(year, month, day);
}