#include "PriorityQueue.h"

void PriorityQueue::insert(Node* toInsert)
{
    m_nodes.push(toInsert);
}

Node* PriorityQueue::peekFront()
{
    return m_nodes.top();
}

Node* PriorityQueue::removeFront()
{
    Node* node = m_nodes.top();
    m_nodes.pop();
    return node;
}

int PriorityQueue::size()
{
    return m_nodes.size();
}

bool PriorityQueue::contains(Node* node)
{
    assert(false);
    return false;
}

