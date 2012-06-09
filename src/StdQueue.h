#ifndef STANDARD_QUEUE_H
#define STANDARD_QUEUE_H

#include <queue>
#include "Queue.h"

class StdQueue : public Queue
{
    public:
        //Constructor, destructor
        StdQueue() {}
        virtual ~StdQueue() {}

        virtual void insert(Node* toInsert);

        virtual Node* peekFront();

        virtual Node* removeFront();

        virtual int size();

        virtual bool contains(Node* node);
    private:
        std::queue<Node*> m_nodes;
};

#endif
