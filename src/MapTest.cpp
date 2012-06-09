#include "gtest/gtest.h"
#include "Search.h"

TEST(MapTest, TwoPointTest)
{
    Map map1("two_point_problem_1_submit.txt");
    ASSERT_FALSE(map1.contains(-1,-1));
    ASSERT_TRUE(map1.contains(1,1));
}

TEST(MapTest, NPoint1Test)
{
    Map map2("n_point_problem_1_submit.txt");
}

TEST(MapTest, NPoint2Test)
{
    Map map3("n_point_problem_2_submit.txt");
}

TEST(MapTest, NPoint3Test)
{
    Map map4("n_point_problem_3_submit.txt");
}
