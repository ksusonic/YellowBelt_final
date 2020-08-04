#pragma once
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Date {
    int year, month, day;
};

ostream& operator<<(ostream& os, const Date &date);

bool operator<(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);


Date ParseDate(istream &in);
