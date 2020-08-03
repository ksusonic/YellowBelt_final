#include "date.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>

class Database {
public:
    void Add(const Date &date, const string &event); // add

    void Print(ostream &os) const; // print

    vector<pair<Date, string>> FindIf(const function<bool(const Date&, const string&)> predicate) const;

    int RemoveIf(const function<bool(const Date&, const string&)> predicate);

    string Last(const Date &date) const;

private:
    map<Date, pair<set<string>, vector<set<string>::iterator>>> storage;
};

ostream &operator<<(ostream &stream, const pair<Date, string>& p);
