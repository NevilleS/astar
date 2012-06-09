#ifndef BLOCK_H
#define BLOCK_H

class Node;

class Block
{
    public:
        Block() : m_node(0), m_obstacle(false), m_path(false), m_point(false) {}
        ~Block() {}

        bool isObstacle() { return m_obstacle; }
		void setObstacle() { m_obstacle = true; }
        Node* getNode() { return m_node; }
        void setNode(Node* node) { m_node = node; }
		bool isPath() { return m_path; }
		void setPath() { m_path = true; }		
	    bool isPoint() { return m_point; }
	    void setPoint() { m_point = true; }
	    void reset(); 
    
	private:
        bool m_obstacle;
		bool m_path;
	    bool m_point;
        Node* m_node;
};

#endif
