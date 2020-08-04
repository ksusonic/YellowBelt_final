#include "date.h"


ostream &operator<<(ostream &os, const Date &date) {
    os << setw(4) << setfill('0') << date.year <<
       '-' << setfill('0') << setw(2) << date.month <<
       '-' << setfill('0') << setw(2) << date.day;
    return os;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <
            tie(rhs.year, rhs.month, rhs.day);
}
bool operator<=(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <=
           tie(rhs.year, rhs.month, rhs.day);
}
bool operator>(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) >
           tie(rhs.year, rhs.month, rhs.day);
}
bool operator>=(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) >=
           tie(rhs.year, rhs.month, rhs.day);
}
bool operator==(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) ==
           tie(rhs.year, rhs.month, rhs.day);
}
bool operator!=(const Date &lhs, const Date &rhs) {
    return tie(lhs.year, lhs.month, lhs.day) !=
           tie(rhs.year, rhs.month, rhs.day);
}

Date ParseDate(istream &in) {
    Date result{};
    in >> result.year;
    in.ignore();
    in >> result.month;
    in.ignore();
    in >> result.day;
    return result;
}