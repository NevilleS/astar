#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        Point() : m_x(0), m_y(0) {}
        Point(int x, int y) : m_x(x), m_y(y) {}
        ~Point() {}

        int getX() { return m_x; }
        int getY() { return m_y; }
        int getDistance(int x, int y) { return abs(m_x-x)+abs(m_y-y); }

    private:
        int m_x;
        int m_y;
};

#endif
