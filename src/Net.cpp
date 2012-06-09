#include "Net.h"
#include "Point.h"
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

class PointTuple
{
    public:
        PointTuple(Point a, int dist) : m_point(a), m_dist(dist) {}
        bool operator>(const PointTuple& other) const
        {
            return m_dist > other.m_dist;
        }
        Point m_point;
        int m_dist;
};

Net::Net(char* net_name, int net_id)
{
    strcpy(m_net_name, net_name);
    m_net_id = net_id;
}

void Net::addPoint(int x, int y)
{
	m_points.push_back(Point(x, y));
}

Point Net::getPoint(int i)
{
	return m_points[i];
}

int Net::numPoints()
{
	return m_points.size();
}

Point Net::sortPoints()
{
    //Find the middle of the Points
    int max_x, max_y, min_x, min_y, new_x, new_y;
    min_x = max_x = m_points[0].getX();
    min_y = max_y = m_points[0].getY();
    for (int i=1; i<numPoints(); i++)
    {
       new_x = m_points[i].getX();
       new_y = m_points[i].getY();
       if (new_x < min_x)
           min_x = new_x;
       else if (new_x > max_x)
           max_x = new_x;
       if (new_y < min_y)
           min_y = new_y;
       else if (new_y > max_y)
           max_y = new_y;
    }
    int mid_x = (max_x - min_x) / 2 + min_x;
    int mid_y = (max_y - min_y) / 2 + min_y;
    //Find the point that's closest to the middle
    std::priority_queue<PointTuple, std::vector<PointTuple>, std::greater<PointTuple> > sortedQueue;
    int mid_index = 0;
    int mid_distance = m_points[0].getDistance(mid_x, mid_y);
    sortedQueue.push(PointTuple(m_points[0], mid_distance));
    int new_distance;
    for(int i=1; i<numPoints(); i++)
    {
        new_distance = m_points[i].getDistance(mid_x, mid_y);
        sortedQueue.push(PointTuple(m_points[i], new_distance));
        if (new_distance < mid_distance)
        {
            mid_index = i;
            mid_distance = new_distance;
        }
    }
    for(int i=0; i<numPoints(); i++)
    {
        m_points[i] = sortedQueue.top().m_point;
        sortedQueue.pop();
    }

    return m_points[0];
}


