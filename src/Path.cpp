#include "Path.h"
#include "Node.h"
#include "Map.h"

using namespace std;

Path::Path(Map& map, Node* start, Node* end, int open, int closed) : m_length(0), m_start(0), m_end(0), m_openNodes(open), m_closedNodes(closed)
{
    // Retrace path from end-->start, counting the length and making copies (Map will
    // delete the old Nodes, but Path needs to save them)
    //cout << "Retracing path from "<<end->m_x<<","<<end->m_y<<" to "<<start->m_x<<","<<start->m_y<<"...";
    m_end = new Node(end->m_x,end->m_y,end->m_gCost,end->m_hCost,end->m_isClosed);
    m_end->m_parent = end->m_parent;
    Node* current = m_end;
    while( current != start ) {
        if ( current == NULL ) {
            m_length = -1;
            return;
        } else {
            map.setPath(current->m_x, current->m_y);
            Node* parent = new Node(current->m_x,current->m_y,current->m_gCost,current->m_hCost,current->m_isClosed);
            parent->m_parent = current->m_parent;
            current = parent->m_parent;
            m_length++;
        }
    }
    m_start = current;
}

void Path::writePath(std::ofstream& out_stream)
{
	Node* curr = m_end;
	while(curr != NULL && curr->m_parent != NULL )
	{
		out_stream << "(" << curr->m_x << "," << curr->m_y << ")-(" << curr->m_parent->m_x << "," << curr->m_parent->m_y << ")\n";		
		curr = curr->m_parent;
	}
}
