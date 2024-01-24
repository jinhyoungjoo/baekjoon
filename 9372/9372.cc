#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void get_graph(Graph &, int);
int get_minimum_weight(const Graph &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int N = 0, M = 0;
  while (T--) {
    std::cin >> N >> M;

    Graph graph(N + 1);
    get_graph(graph, M);

    std::cout << get_minimum_weight(graph, N) << '\n';
  }

  return 0;
}

void get_graph(Graph &graph, int num_edges) {
  int a = 0, b = 0;
  while (num_edges--) {
    std::cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

int get_minimum_weight(const Graph &graph, int num_vertices) {
  std::vector<bool> visited(num_vertices + 1, false);
  std::queue<int> queue;

  int start = 1;
  queue.push(start);
  visited[start] = true;
  int tree_weight = 0;

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int adjacent : graph[front]) {
      if (visited[adjacent])
        continue;

      queue.push(adjacent);
      visited[adjacent] = true;
      tree_weight++;
    }
  }

  return tree_weight;
}
