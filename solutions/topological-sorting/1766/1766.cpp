#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int, int);
  void print_topological_ordering();

private:
  std::vector<std::vector<int>> graph_;
  std::vector<int> inbound_count_;
  int num_vertices_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  Graph graph = Graph(N, M);
  graph.print_topological_ordering();

  return 0;
}

Graph::Graph(int num_vertices, int num_edges) : num_vertices_(num_vertices) {
  graph_ = std::vector<std::vector<int>>(num_vertices + 1);
  inbound_count_ = std::vector<int>(num_vertices_ + 1, 0);

  int A, B;
  while (num_edges--) {
    std::cin >> A >> B;
    graph_[A].push_back(B);
    inbound_count_[B]++;
  }
}

void Graph::print_topological_ordering() {
  std::vector<int> sorted(num_vertices_);
  int current_index = 0;

  std::vector<bool> visited(num_vertices_ + 1, false);
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

  for (int i = 1; i <= num_vertices_; i++) {
    if (inbound_count_[i] != 0)
      continue;

    visited[i] = true;
    queue.push(i);
  }

  while (!queue.empty()) {
    int front = queue.top();
    queue.pop();
    sorted[current_index++] = front;

    for (int &adjacent : graph_[front]) {
      if (visited[adjacent] || --inbound_count_[adjacent] != 0)
        continue;

      visited[adjacent] = true;
      queue.push(adjacent);
    }
  }

  for (int &vertex : sorted)
    std::cout << vertex << ' ';
  std::cout << '\n';
}
