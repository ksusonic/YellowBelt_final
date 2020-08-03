#pragma once
#include <cstdint>
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
    int16_t year;
    uint8_t month;
    uint8_t day;
};

ostream& operator<<(ostream& os, const Date &date);

bool operator<(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);


Date ParseDate(istream &is);
