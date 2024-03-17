#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

int get_solution(MinHeap &);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  int input;
  MinHeap heap;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    heap.push(input);
  }

  std::cout << get_solution(heap) << '\n';

  return 0;
}

int get_solution(MinHeap &heap) {
  int solution = 0, item = 0;

  while (true) {
    item = heap.top();
    heap.pop();
    if (heap.empty())
      break;

    item += heap.top();
    heap.pop();

    solution += item;
    heap.push(item);
  }

  return solution;
}
