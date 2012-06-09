#include "Map.h"
#include "Block.h"
#include "Net.h"
#include "Node.h"
#include <fstream>

using namespace std;


Map::Map(char* fileName)
{
    maps_drawn = 0;
	const char MAX_LINE_SIZE = 100;
	const int ASCII_INT_OFFSET = 48;
	char temp_buffer[MAX_LINE_SIZE];
	std::ifstream in_stream(fileName, ios_base::in);
	//Read the grid size and create the grid
	in_stream.seekg(5, ios_base::cur);
	int grid_x = read_int(in_stream);
	int grid_y = read_int(in_stream);
	in_stream.getline(temp_buffer, MAX_LINE_SIZE);
	//cout << "grid_x: " << grid_x << " grid_y: " << grid_y << endl;
	setSize(grid_x, grid_y);	
	//Ignore the vertical and horizontal capacity
	in_stream.getline(temp_buffer, MAX_LINE_SIZE);
	in_stream.getline(temp_buffer, MAX_LINE_SIZE);
	//Read the number of nets
	in_stream.seekg(8, ios_base::cur);
	int num_nets = read_int(in_stream);
	in_stream.getline(temp_buffer, MAX_LINE_SIZE);
	//cout << "num_nets: " << num_nets << endl;
	//Read the number of obstacles
	in_stream.seekg(14, ios_base::cur);
	int num_obstacles = read_int(in_stream);
	in_stream.getline(temp_buffer, MAX_LINE_SIZE);
	//Read the data for each net, build it, and add it to the list of nets
	for (int i=0; i < num_nets; i++){
		//Read the number of points in the net
		//in_stream.seekg(12, ios_base::cur);
        in_stream.get(temp_buffer, 10);
        int net_id;
        in_stream >> net_id;
		int num_points = read_int(in_stream);
		//Create a new Net and add the points to it
		Net new_net(temp_buffer, net_id);
		for(int j=0; j < num_points; j++)
		{
			in_stream.seekg(2, ios_base::cur);
			int point_x = read_int(in_stream);
			int point_y = read_int(in_stream);
            //cout << "Add point ("<<point_x<<","<<point_y<<")\n";
			new_net.addPoint(point_x, point_y);
			m_grid[point_x][point_y].setPoint();
		}
		//Add the Net to the list of nets
		m_nets.push_back(new_net);	
	}
	//Read the obstacle data
	for (int i=0; i < num_obstacles; i++)
	{
		in_stream.seekg(15, ios_base::cur);
		int x_left = read_int(in_stream);
		int y_bot = read_int(in_stream);
		int x_right = read_int(in_stream);
		int y_top = read_int(in_stream);
        //cout << "Obstacle "<<x_left<<","<<y_bot<<","<<x_right<<","<<y_top<<endl;
		//Update the Blocks in the map
		for (int j=x_left; j <= x_right; j++)
		{
			for(int k=y_bot; k <= y_top; k++)
			{
				m_grid[j][k].setObstacle();
			}
		}
	}
}

bool Map::contains(int x, int y)
{
    return ( 0 <= x && x < m_grid.size() )&&( 0 <= y && y < m_grid[0].size() );
}

bool Map::isObstacle(int x, int y)
{
    return m_grid[x][y].isObstacle();
}

bool Map::isPath(int x, int y)
{
    return m_grid[x][y].isPath();
}

Node* Map::getNode(int x, int y)
{
    return m_grid[x][y].getNode();
}

void Map::setNode(Node* node, int x, int y)
{
    m_grid[x][y].setNode(node);
}

void Map::setPath(int x, int y)
{
	m_grid[x][y].setPath();
}

std::vector<Net> Map::getNets()
{
    return m_nets;
}

void Map::draw(char* filename)
{
	maps_drawn++;
	ofstream out_stream (filename);
	for(int i = 0; i < m_grid[0].size(); i++){
		for(int j = 0; j < m_grid.size(); j++){
			if(m_grid[j][i].isObstacle())
				out_stream << "1,";
			else if (m_grid[j][i].isPoint())
				out_stream << "2,";
			else if(m_grid[j][i].isPath())
				out_stream << "3,";
			else
				out_stream << "0,";	
		}
		out_stream << endl;
	}
	out_stream.close();
}

void Map::clean()
{
	for (int i = 0; i < m_grid[0].size(); i++)
		for (int j = 0; j < m_grid.size(); j++)
			m_grid[j][i].reset();						
}

void Map::setSize(int x, int y)
{
    std::vector<Block> yVector(y);
    m_grid.resize(x, yVector);
}

int Map::read_int(std::ifstream& in_stream)
{
    int i;
    in_stream >> i;
    return i;
}
