#include "date.h"

class Database {
public:
    void Add(const Date &date, const string &event);
    void Print(ostream &os) const;
    template<typename iter>
    iter FindIf(const bool &condition) const; // не то
    int RemoveIf(const bool &criteria);
    string Last(Date date);
};
