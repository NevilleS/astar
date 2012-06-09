#ifndef NET_H
#define NET_H

#include <vector>
#include <string.h>
#include "Point.h"

class Net {
	public:
		Net(){}
        Net(char* net_name, int net_id);
		~Net() {}
		void addPoint(int x, int y);
		Point getPoint(int i);
		int numPoints();
        Point sortPoints();
        char* getName() { return m_net_name; }
        void setName(char* net_name) { strcpy(m_net_name, net_name); }
        int getID() { return m_net_id; }
        void setID(int net_id) { m_net_id = net_id; }
		
	private:
		std::vector<Point> m_points;
        static const int MAX_NAME_SIZE = 20;
        char m_net_name[MAX_NAME_SIZE];
        int m_net_id;
		
};

#endif /* NET_H */

