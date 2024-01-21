#include <iostream>
#include <vector>

using Table = std::vector<std::vector<int>>;

int is_palindrome(Table &, const std::vector<int> &, int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::vector<int> array(N + 1);
  for (int i = 1; i <= N; i++)
    std::cin >> array[i];

  Table memo(N + 1, std::vector<int>(N + 1, -1));

  int M = 0, S = 0, E = 0;
  std::cin >> M;
  while (M--) {
    std::cin >> S >> E;
    std::cout << is_palindrome(memo, array, S, E) << '\n';
  }

  return 0;
}

int is_palindrome(Table &memo, const std::vector<int> &array, int S, int E) {
  if (memo[S][E] != -1)
    return memo[S][E];

  if (S == E) {
    memo[S][E] = 1;
    return 1;
  }

  if (array[S] != array[E]) {
    memo[S][E] = 0;
    return 0;
  }

  if (E == S + 1) {
    memo[S][E] = 1;
    return 1;
  } else {
    memo[S][E] = is_palindrome(memo, array, S + 1, E - 1);
    return memo[S][E];
  }
}
