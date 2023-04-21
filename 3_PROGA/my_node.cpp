#include <iostream>
#include <math.h>
#include "my_node.h"

aks::Point aks::direct_map(Point p, const float &a)
{
    Point res;
    res.x = p.x + p.y + a * p.x * (1 - p.x * p.x);
    res.y = p.y + a * p.x * (1 - p.x * p.x);
    return res;
}

aks::Node::Node(Point p, const float &a)
{
    this->prototype_point = p;
    this->point = direct_map(p, a);
    this->next = nullptr;
};

aks::PointList::PointList(float t)
{
    this->head = this->tail = nullptr;
    push({0, 0});
    a = t;
}
// PointList() {
//     this->head = this->tail = nullptr;
// }
aks::PointList::~PointList()
{
    while (!head) pop();
}

void aks::PointList::push(Point p)
{
    Node *node = new Node(p, a);
    if (!head)
        head = node;
    if (tail)
        tail->next = node;
    tail = node;
}

void aks::PointList::pop()
{
    if (!tail)
        return;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }
    Node *temp_node = head;
    for (; temp_node->next != tail; temp_node = temp_node->next)
        ;
    temp_node->next = nullptr;
    delete tail;
    tail = temp_node;
}

aks::Node* aks::PointList::get_at(int num)
{
    if (num < 0)
        return nullptr;
    Node *node = head;
    int n = 0;
    while (node && n != num && node->next)
    {
        node = node->next;
        n++;
    }
    return (n == num) ? node : nullptr;
}

float aks::PointList::dist_to_next(Node *node)
{
    // if (!node->next) return -1;
    float sq = sqrt((node->next->point.x - node->point.x) *
                        (node->next->point.x - node->point.x) +
                    (node->next->point.y - node->point.y) *
                        (node->next->point.y - node->point.y));
    return sq;
}

void aks::PointList::shreder(const float &h)
{
    shred(head, h);
}

void aks::PointList::shred(Node *node, const float &h)
{
    if (node->next == nullptr)
        return;
    if (dist_to_next(node) >= h)
    {
        Point new_point;
        new_point.x = (node->prototype_point.x + node->next->prototype_point.x) / 2;
        new_point.y = (node->prototype_point.y + node->next->prototype_point.y) / 2;
        Node *new_node = new Node(new_point, a);
        new_node->next = node->next;
        node->next = new_node;
        shred(node, h);
    }
    shred(node->next, h);
}