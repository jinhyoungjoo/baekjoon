#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int, int);
  int get_num_components();

private:
  int num_vertices_;
  std::vector<std::vector<int>> graph_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  Graph graph = Graph(N, M);
  std::cout << graph.get_num_components() << '\n';

  return 0;
}

Graph::Graph(int num_vertices, int num_edges) : num_vertices_(num_vertices) {
  graph_ = std::vector<std::vector<int>>(num_vertices_ + 1);

  int u, v;
  while (num_edges--) {
    std::cin >> u >> v;
    graph_[u].push_back(v);
    graph_[v].push_back(u);
  }
}

int Graph::get_num_components() {
  std::vector<bool> visited(num_vertices_ + 1, false);
  std::queue<int> queue;

  int num_components = 0;
  for (int i = 1; i <= num_vertices_; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    queue.push(i);

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int adjacent : graph_[front]) {
        if (visited[adjacent])
          continue;

        visited[adjacent] = true;
        queue.push(adjacent);
      }
    }

    num_components++;
  }

  return num_components;
}
