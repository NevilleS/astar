#include "Solver.h"
#include "Map.h"
#include "Net.h"
#include "Search.h"
#include "Path.h"
#include <fstream>

using namespace std;

void Solver::run(char* inputFile, char* outputFile, char* mapFile, SolverType type)
{
    Map map(inputFile);
    //cout << "Read file"<<endl;
    std::vector<Net> nets = map.getNets();
    Point start, goal;
    Search search;
    Path path;
    int totalLength = 0;
    ofstream out_stream(outputFile);
    out_stream << "netname netid                       \n";
    for(int i=0; i < nets.size(); i++)
    {
        //cout << "Reading net "<<i<<" of "<<nets.size()<<endl;
        goal = nets[i].sortPoints();

        for(int j=1; j < nets[i].numPoints(); j++)
        {
            //cout << "Connecting from point "<<j<<endl;
            start = nets[i].getPoint(j);
            switch ( type ) {
                case SOLVER_BFS:
                    path = search.runBFS(map, start, goal);
                    break;
                case SOLVER_DFS:
                    path = search.runDFS(map, start, goal);
                    break;
                case SOLVER_ASTAR:
                    path = search.runAStar(map, start, goal);
                    break;
                case SOLVER_MIXED:
                default:
                    if ( j == 1 ) {
                        path = search.runAStar(map, start, goal);
                    } else {
                        path = search.runBFS(map, start, goal);
                    }
                    break;
            }
            cout <<"Found path of length "<<path.getLength()<<", "<<path.getOpenNodes()<<" still open, closed "<<path.getClosedNodes()<<" nodes\n";
            totalLength += path.getLength();
            map.clean();
			path.writePath(out_stream);
		}
        out_stream << "!\n";
        out_stream.seekp(0, ios_base::beg);
        out_stream << nets[i].getName() << " " << nets[i].getID()<< " " << totalLength;
        out_stream.seekp(0, ios_base::end);

        cout << "Found a solution, total length " << totalLength << endl;
        map.draw(mapFile);
	}
	out_stream.close();
	
	//Draw the final map to a file
}
