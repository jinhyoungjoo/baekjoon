#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, S;
  std::cin >> N >> S;

  int number = 0;
  std::vector<int> cumsum(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    std::cin >> number;
    cumsum[i] = cumsum[i - 1] + number;
  }

  int minimum_length = INT_MAX, j = 1;
  for (int i = 1; i <= N; i++) {
    for (; j <= N; j++) {
      if (cumsum[j] - cumsum[i - 1] < S)
        continue;

      minimum_length = std::min(minimum_length, j - i + 1);
      j -= 1;
      break;
    }
  }

  std::cout << (minimum_length == INT_MAX ? 0 : minimum_length) << '\n';

  return 0;
}
