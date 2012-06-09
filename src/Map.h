#ifndef MAP_H
#define MAP_H

#include <vector>
#include <fstream>
#include "Block.h"
#include "Net.h"
#include "Node.h"

class Map
{
public:
        Map() : maps_drawn(0) {}
        Map(char* fileName);
        ~Map() {}

        bool contains(int x, int y);
        bool isObstacle(int x, int y);
        bool isPath(int x, int y);
        Node* getNode(int x, int y);
        void setNode(Node* node, int x, int y);
        std::vector<Net> getNets();
		void setPath(int x, int y);
	void draw(char* mapFile);
	void clean();

    private:
        void setSize(int x, int y);

        std::vector< std::vector<Block> > m_grid;
        std::vector<Net> m_nets;
		int read_int(std::ifstream& in_stream);
	int maps_drawn;
};

#endif
