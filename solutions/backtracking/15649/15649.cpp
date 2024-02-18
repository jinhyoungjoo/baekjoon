#include <iostream>
#include <vector>

void print_combinations(int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, M = 0;
  std::cin >> N >> M;

  print_combinations(N, M);

  return 0;
}

void print_combinations_recursive(std::vector<int> &order,
                                  std::vector<bool> &visited, int N, int M,
                                  int depth) {
  if (depth == M) {
    for (int i = 0; i < M; i++)
      std::cout << order[i] << ' ';
    std::cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    order[depth] = i;
    print_combinations_recursive(order, visited, N, M, depth + 1);

    visited[i] = false;
  }
}

void print_combinations(int N, int M) {
  std::vector<int> order(N);
  std::vector<bool> visited(N, false);

  print_combinations_recursive(order, visited, N, M, 0);
}
