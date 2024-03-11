#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::vector<int> array(N);
  for (auto &item : array)
    std::cin >> item;

  std::sort(array.begin(), array.end());

  for (auto &item : array)
    std::cout << item << '\n';

  return 0;
}
