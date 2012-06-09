#include "Search.h"

#include "PriorityQueue.h"
#include "StdQueue.h"
#include "Stack.h"

#include <iostream>
using namespace std;

Path Search::runAStar(Map& map, Point& start, Point& goal)
{
    PriorityQueue queue;
    return run(queue, map, start, goal);
}

Path Search::runBFS(Map& map, Point& start, Point& goal)
{
    StdQueue queue;
    return run(queue, map, start, goal);
}

Path Search::runDFS(Map& map, Point& start, Point& goal)
{
    Stack stack;
    return run(stack, map, start, goal);
}

Path Search::run(Queue& openQueue, Map& map, Point& start, Point& goal)
{
    int closedNodes = 0;
    Node* startNode = new Node(start);
    openQueue.insert(startNode);
    while(openQueue.size() > 0) {
        Node* currNode = openQueue.removeFront();
        //cout << "Check node " << currNode->m_x <<","<<currNode->m_y<<" cost "<<currNode->m_gCost<<", "<<currNode->m_hCost<<endl;
        if ( currNode->isPoint(goal) || map.isPath(currNode->m_x, currNode->m_y) ) {
            //cout << "Found goal!" << endl;
            return Path(map, startNode, currNode, openQueue.size(), closedNodes);
        } else {
            currNode->m_isClosed = true;
            closedNodes++;
            //cout << "Not goal, expand. Open queue from "<<openQueue.size();
            currNode->expand(openQueue, map, goal);
            //cout << " to "<<openQueue.size()<<endl;
        }
    }
    return Path();
}
