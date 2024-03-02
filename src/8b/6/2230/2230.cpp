#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::vector<long long> array(N);
  for (auto &item : array)
    std::cin >> item;
  std::sort(array.begin(), array.end());

  long long minimum_difference = LLONG_MAX;
  int j = 0;
  for (int i = 0; i < N; i++) {
    for (; j < N; j++) {
      if (array[j] - array[i] < M)
        continue;

      minimum_difference = std::min(minimum_difference, array[j] - array[i]);
      break;
    }
  }
  std::cout << minimum_difference << '\n';

  return 0;
}
