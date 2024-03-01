#include <iostream>
#include <queue>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto cmp = [](int &n1, int &n2) {
    int a = abs(n1), b = abs(n2);
    if (a != b)
      return a > b;

    return n1 > n2;
  };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> heap(cmp);

  int N = 0, input = 0;
  std::cin >> N;
  while (N--) {
    std::cin >> input;
    if (input != 0) {
      heap.push(input);
      continue;
    }

    if (heap.size() > 0) {
      std::cout << heap.top() << '\n';
      heap.pop();
    } else {
      std::cout << 0 << '\n';
    }
  }

  return 0;
}
