#include <iostream>
#include <vector>

int get_num_combinations(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, S = 0;
  std::cin >> N >> S;

  std::vector<int> array(N);
  for (int &item : array)
    std::cin >> item;

  int num_combinations = get_num_combinations(array, S);
  std::cout << num_combinations << '\n';

  return 0;
}

int get_num_combinations_recursive(const std::vector<int> &array, int sum,
                                   int target, int i) {
  if (i == array.size())
    return 0;

  int current_sum = sum + array[i];
  return (current_sum == target ? 1 : 0) +
         get_num_combinations_recursive(array, current_sum, target, i + 1) +
         get_num_combinations_recursive(array, sum, target, i + 1);
}

int get_num_combinations(const std::vector<int> &array, int target) {
  return get_num_combinations_recursive(array, 0, target, 0);
}
