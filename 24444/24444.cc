#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void get_graph(Graph &, int, int);
void traverse_bfs(const Graph &, int, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0, R = 0;
  std::cin >> N >> M >> R;

  Graph graph(N + 1);
  get_graph(graph, N, M);

  traverse_bfs(graph, N, R);
  return 0;
}

void get_graph(Graph &graph, int num_vertices, int num_edges) {
  int u = 0, v = 0;
  for (int i = 0; i < num_edges; i++) {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= num_vertices; i++)
    std::sort(graph[i].begin(), graph[i].end());
}

void traverse_bfs(const Graph &graph, int num_vertices, int start) {
  std::vector<int> order(num_vertices + 1, 0);
  std::queue<int> queue;

  int current = 1;
  order[start] = current;
  queue.push(start);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int adjacent : graph[front]) {
      if (order[adjacent] != 0)
        continue;

      order[adjacent] = ++current;
      queue.push(adjacent);
    }
  }

  for (int i = 1; i <= num_vertices; i++)
    std::cout << order[i] << '\n';
}
