#include "Node.h"
#include "Queue.h"
#include "Map.h"
#include <iostream>
using namespace std;

void Node::expand(Queue& dest, Map& map, Point& goal)
{
    int xCoords[] = {m_x-1,m_x,m_x+1,m_x};
    int yCoords[] = {m_y,m_y+1,m_y,m_y-1};
    for ( int i = 0; i < 4; i++ ) {
        if ( isFree(xCoords[i], yCoords[i], map) ) {
            Node* newNode = new Node(xCoords[i], yCoords[i]);
            map.setNode(newNode,newNode->m_x,newNode->m_y);
            newNode->m_parent = this;
            newNode->m_gCost = m_gCost + 1;
            newNode->m_hCost = goal.getDistance(newNode->m_x,newNode->m_y);
            dest.insert(newNode);
            //cout << "Node "<<m_x<<","<<m_y<<" expanding "<<newNode->m_x<<","<<newNode->m_y<<" with costs "<<newNode->m_gCost<<", "<<newNode->m_hCost<<endl;
        }
    }
}

bool Node::isFree(int x, int y, Map& map)
{
    bool free = (map.contains(x,y))&&(!map.isObstacle(x,y))&&(map.getNode(x,y)==0);
    return free;
}
