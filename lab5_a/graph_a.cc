#include "graph_a.h"

std::vector<int> DepthSearch(graph_t& graph, int start, int goal) {
  std::stack<std::pair<int, std::vector<int>>> stack;
  std::unordered_set<int> visited;

  stack.push({start, {start}});

  while (!stack.empty()) {
    int vertex = stack.top().first;
    std::vector<int> path = stack.top().second;
    stack.pop();

    if (vertex == goal) {
      return path;
    }

    if (visited.find(vertex) != visited.end()) {
      continue;
    }

    visited.insert(vertex);

    for (int neighbor : graph[vertex]) {
      if (visited.find(neighbor) == visited.end()) {
        stack.push({neighbor, path});
        stack.top().second.push_back(neighbor);
      }
    }
  }

  return {};
}

std::vector<int> WidthSearch(graph_t& graph, int start, int goal) {
  std::queue<std::pair<int, std::vector<int>>> queue;
  std::unordered_set<int> visited;

  queue.push({start, {start}});

  while (!queue.empty()) {
    int vertex = queue.front().first;
    std::vector<int> path = queue.front().second;
    queue.pop();

    if (vertex == goal) {
      return path;
    }

    if (visited.find(vertex) != visited.end()) {
      continue;
    }

    visited.insert(vertex);

    for (int neighbor : graph[vertex]) {
      if (visited.find(neighbor) == visited.end()) {
        queue.push({neighbor, path});
        queue.back().second.push_back(neighbor);
      }
    }
  }

  return {};
}

std::vector<int> Dijkstra(graph_t& graph, int start, int goal) {
  int numVertices = graph.size();
  std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
  std::vector<int> previous(numVertices, -1);
  std::vector<bool> visited(numVertices, false);

  distances[start] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,std::greater<>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }

    visited[u] = true;

    for (int v = 0; v < numVertices; v++) {
      if (graph[u][v] != 0) {
        int weight = graph[u][v];

        if (distances[u] + weight < distances[v]) {
          distances[v] = distances[u] + weight;
          previous[v] = u;
          pq.push({distances[v], v});
        }
      }
    }
  }

  std::vector<int> path;
  int current = goal;

  while (current != -1) {
    path.insert(path.begin(), current);
    current = previous[current];
  }

  return path;
}