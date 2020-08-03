#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison &comp_to, const Date &date_to)
    : comparison(comp_to)
    , date(date_to) {}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) {
    return false;
}

EventComparisonNode::EventComparisonNode(const Comparison &comp_to, const string &event_to)
    : comp(comp_to)
    , event(event_to)
    {}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) {
    return false;
}


LogicalOperationNode::LogicalOperationNode(const LogicalOperation operation_to,
                                           const shared_ptr<Node> &lhs, const shared_ptr<Node> &rhs)
        : operation(operation_to)
        , lhs_node(lhs)
        , rhs_node(rhs)
    {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) {
    return false;
}

bool EmptyNode::Evaluate(const Date &date, const string &event) {
    return false;
}
