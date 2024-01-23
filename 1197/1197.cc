#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using Edge = std::tuple<int, int, int>; // vertex, vertex, weight

int get_mst_weight(std::vector<Edge> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V = 0, E = 0;
  std::cin >> V >> E;

  std::vector<Edge> edges(E);
  for (auto &[v1, v2, weight] : edges)
    std::cin >> v1 >> v2 >> weight;

  std::cout << get_mst_weight(edges, V) << '\n';

  return 0;
}

int find(std::vector<int> &parent, int x) {
  while (parent[x] != x) {
    parent[x] = parent[parent[x]];
    x = parent[x];
  }

  return x;
}

void merge(std::vector<int> &parent, int x, int y) {
  int parent_x = find(parent, x);
  int parent_y = find(parent, y);
  parent[parent_x] = parent[parent_y];
}

int get_mst_weight(std::vector<Edge> &edges, int num_vertices) {
  std::sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) {
    return std::get<2>(e1) < std::get<2>(e2);
  });

  std::vector<int> parent(num_vertices + 1);
  for (int i = 1; i <= num_vertices; i++)
    parent[i] = i;

  int total_weight = 0;
  for (auto &[v1, v2, weight] : edges) {
    if (find(parent, v1) == find(parent, v2))
      continue;

    total_weight += weight;
    merge(parent, v1, v2);
  }

  return total_weight;
}
