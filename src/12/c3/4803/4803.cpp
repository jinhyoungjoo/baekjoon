#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
  Graph(int, int);
  int get_num_trees();

private:
  int num_vertices_;
  std::vector<std::vector<int>> graph_;
};

void print_num_trees(int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_vertices, num_edges, case_index = 1;
  for (;; case_index++) {
    std::cin >> num_vertices >> num_edges;
    if (num_vertices == 0 && num_edges == 0)
      break;

    Graph graph = Graph(num_vertices, num_edges);
    int num_trees = graph.get_num_trees();
    print_num_trees(case_index, num_trees);
  }

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

int Graph::get_num_trees() {
  int num_trees = 0;

  std::vector<bool> visited(num_vertices_ + 1, false);
  std::queue<int> queue;

  for (int i = 1; i <= num_vertices_; i++) {
    if (visited[i])
      continue;

    int num_edges = 0, num_vertices = 0;

    visited[i] = true;
    queue.push(i);
    num_vertices++;
    num_edges += graph_[i].size();

    while (!queue.empty()) {
      int front = queue.front();
      queue.pop();

      for (int &adjacent : graph_[front]) {
        if (visited[adjacent])
          continue;

        visited[adjacent] = true;
        queue.push(adjacent);
        num_vertices++;
        num_edges += graph_[adjacent].size();
      }
    }

    if (num_vertices * 2 != num_edges + 2)
      continue;
    num_trees++;
  }

  return num_trees;
}

void print_num_trees(int case_index, int num_trees) {
  std::cout << "Case " << case_index << ": ";
  switch (num_trees) {
  case 0:
    std::cout << "No trees.\n";
    break;

  case 1:
    std::cout << "There is one tree.\n";
    break;

  default:
    std::cout << "A forest of " << num_trees << " trees.\n";
    break;
  }
}
