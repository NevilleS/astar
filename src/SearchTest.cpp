#include "gtest/gtest.h"
#include "Solver.h"

TEST(SolverTest, TwoPointsAStarTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("two_point_problem_1_submit.txt", "two_point_problem_1_submit_astar.sln", "two_point_problem_1_submit_astar.map", Solver::SOLVER_ASTAR);
}

TEST(SolverTest, TwoPointsBFSTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("two_point_problem_1_submit.txt", "two_point_problem_1_submit_bfs.sln", "two_point_problem_1_submit_bfs.map", Solver::SOLVER_BFS);
}

TEST(SolverTest, TwoPointsDFSTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("two_point_problem_1_submit.txt", "two_point_problem_1_submit_dfs.sln", "two_point_problem_1_submit_dfs.map", Solver::SOLVER_DFS);
}

TEST(SolverTest, NPoints1AStarTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_1_submit.txt", "n_point_problem_1_submit_astar.sln", "n_point_problem_1_submit_astar.map", Solver::SOLVER_ASTAR);
}

TEST(SolverTest, NPoints1MixedTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_1_submit.txt", "n_point_problem_1_submit_mixed.sln", "n_point_problem_1_submit_mixed.map", Solver::SOLVER_MIXED);
}

TEST(SolverTest, NPoints2AStarTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_2_submit.txt", "n_point_problem_2_submit_astar.sln", "n_point_problem_2_submit_astar.map", Solver::SOLVER_ASTAR);
}

TEST(SolverTest, NPoints2MixedTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_2_submit.txt", "n_point_problem_2_submit_mixed.sln", "n_point_problem_2_submit_mixed.map", Solver::SOLVER_MIXED);
}

TEST(SolverTest, NPoints3AStarTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_3_submit.txt", "n_point_problem_3_submit_astar.sln", "n_point_problem_3_submit_astar.map", Solver::SOLVER_ASTAR);
}

TEST(SolverTest, NPoints3MixedTest)
{
    // Check that search finds the correct path between two points
    Solver solver;
    solver.run("n_point_problem_3_submit.txt", "n_point_problem_3_submit_mixed.sln", "n_point_problem_3_submit_mixed.map", Solver::SOLVER_MIXED);
}

