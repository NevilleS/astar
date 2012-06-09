#ifndef SEARCH_H
#define SEARCH_H

#include "Queue.h"
#include "Path.h"
#include "Point.h"
#include "Map.h"

class Search
{
    public:
        //Constructor, destructor
        Search() {}
        ~Search() {}

        Path runAStar(Map& map, Point& start, Point& goal);
        Path runBFS(Map& map, Point& start, Point& goal);
        Path runDFS(Map& map, Point& start, Point& goal);

    private:
        Path run(Queue& queue, Map& map, Point& start, Point& goal);
        void cleanup(Map& map);
};

#endif
