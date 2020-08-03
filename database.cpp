#include "database.h"
using namespace std;

void Database::Add(const Date &date, const string &event) {
    storage[date].insert(event);
}

void Database::Print(ostream &os) const {
    for (const auto &item: storage) {
        for (const auto &event : item.second) {
            cout << item.first << " " << event << endl;
        }
    }
}

int Database::RemoveIf(const bool &condition) {
    return 0;
}

string Database::Last(const Date &date) const {
    return std::string();
}

vector<pair<Date, string>> Database::FindIf(const function<bool(const Date &, const string &)> predicate) {
    return vector<pair<Date, string>>();
}
