#ifndef _MY_NODE_H_
#define _MY_NODE_H_ 1

namespace aks {
    struct Point { float x, y;};
    Point direct_map(Point p, const float &a);
    class Node {
    public:
        Point point, prototype_point;
        Node *next;
        Node(Point p, const float &a);
    };
    class PointList {
    public:
        Node *head, *tail;
        float a;
        PointList(float t);
        ~PointList();
        void push(Point p);
        void pop();
        Node* get_at(int num);
        float dist_to_next(Node *node);
        void shreder(const float &h);
        void shred(Node *node, const float &h);
    };
};
#endif