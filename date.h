#pragma once
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class Date {
public:
    Date(int new_year, int new_month, int new_day);
    string GetString() const;
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    const int year;
    const int month;
    const int day;
};

ostream& operator<<(ostream& os, const Date &date);

bool operator<(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);


Date ParseDate(istream &in);
