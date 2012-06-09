#include "StdQueue.h"

void StdQueue::insert(Node* toInsert)
{
    m_nodes.push(toInsert);
}

Node* StdQueue::peekFront()
{
    return m_nodes.front();
}

Node* StdQueue::removeFront()
{
    Node* node = m_nodes.front();
    m_nodes.pop();
    return node;
}

int StdQueue::size()
{
    return m_nodes.size();
}

bool StdQueue::contains(Node* node)
{
    assert(false);
    return false;
}

