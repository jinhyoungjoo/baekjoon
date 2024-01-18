#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using WeightedTree = std::vector<std::vector<std::tuple<int, int>>>;
using DistanceMatrix = std::vector<std::vector<int>>;

void get_input(WeightedTree &, int);
std::tuple<int, int> traverse(const WeightedTree &, int, int);
int get_diameter(const WeightedTree &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V = 0;
  std::cin >> V;

  WeightedTree tree(V + 1);
  get_input(tree, V);

  std::cout << get_diameter(tree, V) << '\n';

  return 0;
}

void get_input(WeightedTree &tree, int num_vertices) {
  int node = 0, adjacent_node = 0, weight = 0;
  for (int i = 0; i < num_vertices; i++) {
    std::cin >> node;

    while (true) {
      std::cin >> adjacent_node;
      if (adjacent_node == -1)
        break;

      std::cin >> weight;
      tree[node].push_back({adjacent_node, weight});
      tree[adjacent_node].push_back({node, weight});
    }
  }
}

std::tuple<int, int> traverse(const WeightedTree &tree, int num_vertices,
                              int start) {
  int furthest = 0, maximum_distance = 0;
  std::queue<int> queue;
  std::vector<int> distance(num_vertices + 1, -1);

  queue.push(start);
  distance[start] = 0;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (const auto &[adjacent, weight] : tree[front]) {
      if (distance[adjacent] != -1)
        continue;

      distance[adjacent] = distance[front] + weight;
      queue.push(adjacent);

      if (distance[adjacent] > maximum_distance) {
        maximum_distance = distance[adjacent];
        furthest = adjacent;
      }
    }
  }

  return {furthest, maximum_distance};
}

int get_diameter(const WeightedTree &tree, int num_vertices) {
  int furthest = std::get<0>(traverse(tree, num_vertices, 1));
  int diameter = std::get<1>(traverse(tree, num_vertices, furthest));
  return diameter;
}
