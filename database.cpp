#include "database.h"
using namespace std;

void Database::Add(const Date &date, const string &event) {
    if (storage.count(date) > 0) {
        auto it = storage[date].first.insert(event);
        if (it.second) {
            storage[date].second.push_back(it.first);
        }
    } else {
        auto it = storage[date].first.insert(event);
        storage[date].second.push_back(it.first);
    }
}

void Database::Print(ostream &os) const {
    for (const auto &item: storage) {
        for (const auto &event : item.second.second) {
            cout << item.first << " " << *event << endl;
        }
    }
}


string Database::Last(const Date &date) const {
    auto it = storage.upper_bound(date);

    if (it != storage.begin()) {
        return (*prev(it)).first.GetString() + ' ' + *(prev(it))->second.second.back();
    } else {
        return "No entries";
    }
}

int Database::RemoveIf(const function<bool(const Date &, const string &)> predicate) {
    int counter = 0;

    for (auto date_it = storage.begin(); date_it != storage.end(); ) {
        for (auto event_it = (*date_it).second.second.begin(); event_it != (*date_it).second.second.end(); ) {
            if (predicate((*date_it).first, *(*event_it))) {
                storage[(*date_it).first].first.erase(*(*event_it));
                event_it = storage[(*date_it).first].second.erase(event_it);

                counter++;
            }
            else {
                event_it++;
            }
        }

        if (storage[(*date_it).first].first.size() == 0) {
            date_it = storage.erase(date_it);
        }
        else {
            date_it++;
        }
    }

    return counter;}

vector<pair<Date, string>> Database::FindIf(const function<bool(const Date&,
        const string &)> predicate) const {
    vector<pair<Date,string>> result;
    for (const auto &entry : storage) {
        for (auto &it : entry.second.second) {
            if (predicate(entry.first, *it)) {
                result.push_back(make_pair(entry.first, *it));
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &stream, const pair<Date, string>& p) {
    stream << p.first << ' ' << p.second;
    return stream;
}