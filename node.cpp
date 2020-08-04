#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison &comp_to, const Date &date_to)
    : comparison(comp_to)
    , date(date_to) {}

bool DateComparisonNode::Evaluate(const Date &date_to, const string &event) const {
    switch (comparison) {
        case Less:
            return date_to < date;
        case LessOrEqual:
            return  date_to <= date;
        case Greater:
            return date_to > date;
        case GreaterOrEqual:
            return date_to >= date;
        case Equal:
            return date_to == date;
        case NotEqual:
            return date_to != date;
    }
    return true; // unreachable
}

EventComparisonNode::EventComparisonNode(const Comparison &comp_to, const string &event_to)
    : comp(comp_to)
    , event(event_to)
    {}

bool EventComparisonNode::Evaluate(const Date &date, const string &event_to) const {
    switch (comp) {
        case Less:
            return event_to < event;
        case LessOrEqual:
            return event_to <= event;
        case Greater:
            return event_to > event;
        case GreaterOrEqual:
            return event_to >= event;
        case Equal:
            return event_to == event;
        case NotEqual:
            return event_to != event;
    }
    return true; // unreachable
}


LogicalOperationNode::LogicalOperationNode(const LogicalOperation operation_to,
                                           const shared_ptr<Node> &lhs, const shared_ptr<Node> &rhs)
        : operation(operation_to)
        , lhs_node(lhs)
        , rhs_node(rhs)
    {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch (operation) {
        case And:
            return lhs_node->Evaluate(date,event) && rhs_node->Evaluate(date,event);
        case Or:
            return lhs_node->Evaluate(date,event) || rhs_node->Evaluate(date,event);
    }
    return true; // unreachable
}

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}
