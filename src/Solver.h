#ifndef SOLVER_H
#define SOLVER_H

#include "Map.h"
#include "Search.h"

class Solver
{
    public:
        enum SolverType
        {
            SOLVER_ASTAR = 0,
            SOLVER_BFS,
            SOLVER_DFS,
            SOLVER_MIXED,
            SOLVER_COUNT
        };
        //Constructor, destructor
        Solver() {}
        ~Solver() {}

        void run(char* inputFile, char* outputFile, char* mapFile, SolverType type);
};

#endif
