#include <algorithm>
#include <iostream>
#include <vector>

int get_solution(std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::vector<int> array(N);
  for (int &item : array)
    std::cin >> item;

  int x = 0;
  std::cin >> x;

  std::cout << get_solution(array, x) << '\n';

  return 0;
}

int get_solution(std::vector<int> &array, int target) {
  std::sort(array.begin(), array.end());

  int left = 0, right = array.size() - 1, solution = 0;
  while (left < right) {
    int sum = array[left] + array[right];

    if (sum > target)
      right--;
    else if (sum < target)
      left++;
    else {
      solution++;
      left++;
      right--;
    }
  }

  return solution;
}
