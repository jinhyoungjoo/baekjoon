#include <array>
#include <iostream>

#define MAX_INDEX_VALUE 12

using Count = std::array<int, MAX_INDEX_VALUE>;

int get_count(Count &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Count num_combinations;
  num_combinations.fill(-1);

  int num_testcases = 0;
  std::cin >> num_testcases;

  int input = 0;
  while (num_testcases--) {
    std::cin >> input;
    std::cout << get_count(num_combinations, input) << '\n';
  }

  return 0;
}

int get_count(Count &num_combinations, int index) {
  if (num_combinations[index] != -1)
    return num_combinations[index];

  switch (index) {
  case 1:
    num_combinations[index] = 1;
    return 1;
  case 2:
    num_combinations[index] = 2;
    return 2;
  case 3:
    num_combinations[index] = 4;
    return 4;
  }

  int count = 0;
  count += get_count(num_combinations, index - 1);
  count += get_count(num_combinations, index - 2);
  count += get_count(num_combinations, index - 3);

  num_combinations[index] = count;
  return count;
}
