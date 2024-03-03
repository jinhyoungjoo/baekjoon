#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> array(N);
  for (int &item : array)
    std::cin >> item;
  std::sort(array.begin(), array.end());

  int M, target;
  std::cin >> M;

  while (M--) {
    std::cin >> target;
    std::cout << (std::binary_search(array.begin(), array.end(), target)
                      ? "1\n"
                      : "0\n");
  }

  return 0;
}
