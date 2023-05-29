#include <gtest/gtest.h>

#include "graph_a.h"

TEST(DepthSearchTest, PathExists) {
  graph_t graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4, 5}, {2, 3}, {3}};

  std::vector<int> expected_path = {0, 2, 4, 3, 5};
  std::vector<int> actual_path = DepthSearch(graph, 0, 5);

  ASSERT_EQ(expected_path, actual_path);
}

TEST(DepthSearchTest, NoPathExists) {
  graph_t graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4, 5}, {2, 3}, {3}};

  std::vector<int> expected_path;
  std::vector<int> actual_path = DepthSearch(graph, 0, 6);

  ASSERT_EQ(expected_path, actual_path);
}

TEST(WidthSearchTest, PathExists) {
  graph_t graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4, 5}, {2, 3}, {3}};

  std::vector<int> expected_path = {0, 1, 3, 5};
  std::vector<int> actual_path = WidthSearch(graph, 0, 5);

  ASSERT_EQ(expected_path, actual_path);
}

TEST(WidthSearchTest, NoPathExists) {
  graph_t graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4, 5}, {2, 3}, {3}};

  std::vector<int> expected_path;
  std::vector<int> actual_path = WidthSearch(graph, 0, 6);

  ASSERT_EQ(expected_path, actual_path);
}

TEST(DijkstraTest, PathExists) {
  graph_t graph = {{0, 4, 0, 0, 0, 0},  {4, 0, 8, 0, 0, 0},
                   {0, 8, 0, 7, 0, 4},  {0, 0, 7, 0, 9, 14},
                   {0, 0, 0, 9, 0, 10}, {0, 0, 4, 14, 10, 0}};

  std::vector<int> expected_path = {0, 1, 2, 5, 4};
  std::vector<int> actual_path = Dijkstra(graph, 0, 4);

  ASSERT_EQ(expected_path, actual_path);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
