#ifndef LAB5_GRAPH_A_H
#define LAB5_GRAPH_A_H

#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

typedef const std::vector<std::vector<int>> graph_t;

std::vector<int> DepthSearch(graph_t& graph, int start, int goal);
std::vector<int> WidthSearch(graph_t& graph, int start, int goal);
std::vector<int> Dijkstra(graph_t& graph, int start, int goal);

#endif  // LAB5_GRAPH_A_H
