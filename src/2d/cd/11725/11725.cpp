#include <iostream>
#include <queue>
#include <vector>

class Tree {
public:
  Tree(int);
  void print_parents();

private:
  int num_vertices_;
  std::vector<std::vector<int>> tree_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  Tree tree = Tree(N);
  tree.print_parents();

  return 0;
}

Tree::Tree(int num_vertices) : num_vertices_(num_vertices) {
  tree_ = std::vector<std::vector<int>>(num_vertices + 1);

  int w, v;
  for (int i = 1; i < num_vertices; i++) {
    std::cin >> w >> v;
    tree_[w].push_back(v);
    tree_[v].push_back(w);
  }
}
void Tree::print_parents() {
  std::vector<int> parent(num_vertices_ + 1, -1);

  std::vector<bool> visited(num_vertices_ + 1, false);
  std::queue<int> queue;

  int start = 1;
  visited[start] = true;
  queue.push(start);

  while (!queue.empty()) {
    int front = queue.front();
    queue.pop();

    for (int adjacent : tree_[front]) {
      if (visited[adjacent])
        continue;

      parent[adjacent] = front;
      visited[adjacent] = true;
      queue.push(adjacent);
    }
  }

  for (int i = 2; i <= num_vertices_; i++)
    std::cout << parent[i] << '\n';
}
