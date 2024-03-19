#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using Meeting = std::pair<int, int>;

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::vector<Meeting> meetings(N);
  for (auto &[start, end] : meetings)
    std::cin >> start >> end;

  auto cmp = [](const Meeting &m1, const Meeting &m2) {
    return (m1.first == m2.first) ? m1.second > m2.second : m1.first > m2.first;
  };
  std::priority_queue<Meeting, std::vector<Meeting>, decltype(cmp)> heap(cmp);

  for (Meeting &item : meetings)
    heap.push(item);

  int num_meetings = 0;

  int current_end = 0;
  while (!heap.empty()) {
    auto [start, end] = heap.top();
    heap.pop();

    if (start >= current_end) {
      num_meetings++;
      current_end = end;
      continue;
    }

    if (end < current_end)
      current_end = end;
  }

  std::cout << num_meetings << '\n';

  return 0;
}
