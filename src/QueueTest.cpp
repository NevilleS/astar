#include "gtest/gtest.h"
#include "StdQueue.h"
#include "PriorityQueue.h"
#include "Stack.h"

std::ostream& operator<<(std::ostream& os, const Node* a)
{
    os << "Node(" << a->m_x << ", " << a->m_y << ", "
       << a->m_gCost << ", " << a->m_hCost << ")";
    return os;
}

TEST(QueueTest, InsertTest)
{
    // Check that inserting a node stores it correctly
    StdQueue queue;
    Node n;
    ASSERT_EQ(0, queue.size());
    queue.insert(&n);
    ASSERT_EQ(1, queue.size());
    ASSERT_EQ(&n, queue.removeFront());
}

TEST(QueueTest, QueueFIFOTest)
{
    // Check that regular queue is FIFO
    StdQueue queue;
    Node n1(0,1,4,5), n2(1,2,4,3),
         n3(2,1,3,6), n4(1,0,4,7);
    queue.insert(&n1);
    queue.insert(&n2);
    queue.insert(&n3);
    queue.insert(&n4);
    // Order should be n1,n2,n3,n4
    ASSERT_EQ(&n1, queue.removeFront());
    ASSERT_EQ(&n2, queue.removeFront());
    ASSERT_EQ(&n3, queue.removeFront());
    ASSERT_EQ(&n4, queue.removeFront());
}

TEST(QueueTest, PrioritySortTest)
{
    // Check that inserting several nodes sorts them
    // in order of f (g+h)
    PriorityQueue queue;
    Node n1(0,1,4,5,false), n2(1,2,4,3,false),
         n3(2,1,3,6,false), n4(1,0,4,7,false);
    queue.insert(&n1);
    queue.insert(&n2);
    queue.insert(&n3);
    queue.insert(&n4);
    // Order should be n2,n3,n1,n4
    ASSERT_EQ(&n2, queue.removeFront());
    ASSERT_EQ(&n3, queue.removeFront());
    ASSERT_EQ(&n1, queue.removeFront());
    ASSERT_EQ(&n4, queue.removeFront());
}

TEST(QueueTest, StackTest)
{
    // Check that inserting several nodes to Stack acts as LIFO
    Stack queue; // yeah, that's terrible naming, w/e
    Node n1(0,1,4,5,false), n2(1,2,4,3,false),
         n3(2,1,3,6,false), n4(1,0,4,7,false);
    queue.insert(&n1);
    queue.insert(&n2);
    queue.insert(&n3);
    queue.insert(&n4);
    // Order should be n4,n3,n2,n1
    ASSERT_EQ(&n4, queue.removeFront());
    ASSERT_EQ(&n3, queue.removeFront());
    ASSERT_EQ(&n2, queue.removeFront());
    ASSERT_EQ(&n1, queue.removeFront());
}
