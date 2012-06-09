#ifndef PATH_H
#define PATH_H

#include "Map.h"
#include "Node.h"
#include <fstream>

class Path
{
    public:
        Path() : m_start(0), m_end(0), m_length(-1), m_openNodes(0), m_closedNodes(0) {}
        Path(Map& map, Node* start, Node* end, int open, int closed);
        ~Path() {}

        int getComplete() { return (m_length != -1); }
        int getLength() { return m_length; }
        int getOpenNodes() { return m_openNodes; }
        int getClosedNodes() { return m_closedNodes; }
		void writePath(std::ofstream& out_stream);

    private:
        int m_length;
        int m_openNodes;
        int m_closedNodes;
        Node* m_start;
        Node* m_end;
};

#endif
