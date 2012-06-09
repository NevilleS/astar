#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Point.h"

// forward declarations
class Queue;
class Map;

class Node
{
    public:
		Node(int x, int y, int g, int h) 
            : m_x(x), m_y(y), m_gCost(g), m_hCost(h),
              m_isClosed(false), m_parent(NULL) {}
	
        Node(int x, int y, int g, int h, bool isClosed) 
            : m_x(x), m_y(y), m_gCost(g), m_hCost(h),
              m_isClosed(isClosed), m_parent(NULL) {}

        Node() : m_x(0), m_y(0), m_gCost(0), m_hCost(0),
                 m_isClosed(false), m_parent(NULL) {}

        Node(Point& pt) : m_x(pt.getX()), m_y(pt.getY()), m_gCost(0),
                          m_hCost(0), m_isClosed(false), m_parent(NULL) {}

        Node(int x, int y) : m_x(x), m_y(y), m_gCost(0), m_hCost(0), 
                             m_isClosed(false), m_parent(NULL) {}

        Node(Node* c) : m_x(c->m_x), m_y(c->m_y), m_gCost(c->m_gCost), m_hCost(c->m_hCost),
              m_isClosed(c->m_isClosed), m_parent(c->m_parent) {}

        ~Node() {}


        // Compare two nodes, for sorting
        bool operator>(const Node &a) const
        {
            if ( (m_gCost+m_hCost) == (a.m_gCost+a.m_hCost) ) {
                return (m_gCost > a.m_gCost);
            } else {
                return (m_gCost+m_hCost) > (a.m_gCost+a.m_hCost);
            }
        }

        bool operator==(const Node&a) const
        {
            return (m_x == a.m_x) &&
                   (m_y == a.m_y) &&
                   (m_gCost == a.m_gCost) &&
                   (m_hCost == a.m_hCost) &&
                   (m_isClosed == a.m_isClosed);
        }


        bool isPoint(Point& pt)
        {
            return (m_x==pt.getX())&&(m_y==pt.getY());
        }

        void expand(Queue& dest, Map& map, Point& goal);

        bool isFree(int x, int y, Map& map);

        int m_x;
        int m_y;
        int m_gCost;
        int m_hCost;
        bool m_isClosed;
        Node* m_parent;
};

#endif
