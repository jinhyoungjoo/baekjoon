#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int, int);
  void print_topological_sorting();

private:
  std::vector<std::vector<int>> graph_;
  std::vector<int> inbound_;
  int num_vertices_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  Graph graph = Graph(N, M);
  graph.print_topological_sorting();

  return 0;
}

Graph::Graph(int num_vertices, int num_input_lines)
    : num_vertices_(num_vertices) {
  graph_ = std::vector<std::vector<int>>(num_vertices + 1);
  inbound_ = std::vector<int>(num_vertices_ + 1, 0);

  while (num_input_lines--) {
    int input_count = 0;
    std::cin >> input_count;
    if (input_count == 0)
      continue;

    int prev = 0, next = 0;
    std::cin >> prev;

    for (int i = 1; i < input_count; i++) {
      std::cin >> next;
      graph_[prev].push_back(next);
      inbound_[next]++;
      prev = next;
    }
  }
}
void Graph::print_topological_sorting() {
  std::vector<int> sorted(num_vertices_ + 1);
  int current_index = 0;

  std::vector<bool> visited(num_vertices_ + 1, false);
  std::queue<int> queue;

  for (int i = 1; i <= num_vertices_; i++) {
    if (inbound_[i] != 0)
      continue;

    visited[i] = true;
    queue.push(i);
    sorted[current_index++] = i;
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int &adjacent : graph_[front]) {
      if (visited[adjacent])
        continue;
      if (--inbound_[adjacent] != 0)
        continue;

      visited[adjacent] = true;
      queue.push(adjacent);
      sorted[current_index++] = adjacent;
    }
  }

  for (int i = 1; i <= num_vertices_; i++) {
    if (!visited[i]) {
      std::cout << "0\n";
      return;
    }
  }

  for (int i = 0; i < num_vertices_; i++)
    std::cout << sorted[i] << '\n';
}
