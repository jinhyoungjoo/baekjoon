#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> minimum_operations(N + 1, INT_MAX);
  minimum_operations[1] = 0;

  for (int i = 1; i < N; i++) {
    int current_count = minimum_operations[i];

    int target_index[] = {i + 1, i * 2, i * 3};
    for (int j = 0; j < 3; j++) {
      if (target_index[j] > N)
        continue;

      minimum_operations[target_index[j]] =
          std::min(minimum_operations[target_index[j]], current_count + 1);
    }
  }

  std::cout << minimum_operations[N] << '\n';

  return 0;
}
