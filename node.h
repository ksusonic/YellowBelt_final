#pragma once
#include "date.h"

#include <memory>

using namespace std;

enum Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum LogicalOperation {
    And, Or
};

class Node {
public:
    virtual bool Evaluate(const Date&date, const string&event) const = 0;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison &comp_to, const Date &date_to);
    bool Evaluate(const Date &date_to, const string &event) const override;

private:
    const Comparison comparison;
    const Date date;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison &comp_to, const string &event_to);
    bool Evaluate(const Date &date, const string &event_to) const override;

private:
    const Comparison comp;
    const string event;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation operation_to,
                         const shared_ptr<Node> &lhs, const shared_ptr<Node> &rhs);
    bool Evaluate(const Date &date, const string &event) const override;

private:
    const LogicalOperation operation;
    shared_ptr<Node> lhs_node, rhs_node;
};

struct EmptyNode : public Node {
    bool Evaluate(const Date &date, const string &event) const override;
};

void TestDateComparisonNode();

void TestEventComparisonNode();

void TestLogicalOperationNode();
