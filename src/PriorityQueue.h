#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>
#include <vector>
#include "Queue.h"

class PriorityQueue : public Queue
{
    public:
        //Constructor, destructor
        PriorityQueue() {}
        virtual ~PriorityQueue() {}

        virtual void insert(Node* toInsert);

        virtual Node* peekFront();

        virtual Node* removeFront();

        virtual int size();

        virtual bool contains(Node* node);
    private:
        class CompareFunctor
        {
            public:
                virtual bool operator()(Node* a, Node* b) {
                    return (*a > *b);
                }
        };
        std::priority_queue<Node*, std::vector<Node*>, CompareFunctor> m_nodes;
};

#endif
