#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void get_permutation_information(Graph &, std::vector<int> &, int);
void print_topological_sorting(const Graph &, std::vector<int> &);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_students = 0, num_comparisons = 0;
  std::cin >> num_students >> num_comparisons;

  Graph student_graph(num_students + 1);
  std::vector<int> in_degrees(num_students + 1, 0);
  get_permutation_information(student_graph, in_degrees, num_comparisons);

  print_topological_sorting(student_graph, in_degrees);

  return 0;
}

void get_permutation_information(Graph &graph, std::vector<int> &in_degrees,
                                 int num_edges) {
  int w = 0, v = 0;
  while (num_edges--) {
    std::cin >> w >> v;
    graph[w].push_back(v);
    in_degrees[v]++;
  }
}

void print_topological_sorting(const Graph &graph,
                               std::vector<int> &in_degrees) {
  unsigned long num_vertices = graph.size() - 1;

  int current_index = 0;
  std::vector<int> sorted_vertices(num_vertices);

  std::vector<bool> visited(num_vertices, false);
  std::queue<int> queue;

  for (int i = 1; i <= num_vertices; i++) {
    if (in_degrees[i] != 0)
      continue;

    visited[i] = true;
    queue.push(i);
    sorted_vertices[current_index++] = i;
  }

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int adjacent : graph[front]) {
      if (--in_degrees[adjacent] != 0)
        continue;

      visited[adjacent] = true;
      queue.push(adjacent);
      sorted_vertices[current_index++] = adjacent;
    }
  }

  for (int vertex : sorted_vertices)
    std::cout << vertex << ' ';
  std::cout << '\n';
}
