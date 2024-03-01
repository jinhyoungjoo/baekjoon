#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Jewel {
  int weight;
  int value;
};

long long get_maximum_value(std::vector<Jewel> &, std::vector<int> &);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, K = 0;
  std::cin >> N >> K;

  std::vector<Jewel> jewels(N);
  for (auto &jewel : jewels)
    std::cin >> jewel.weight >> jewel.value;

  std::vector<int> bags(K);
  for (auto &bag : bags)
    std::cin >> bag;

  std::cout << get_maximum_value(jewels, bags) << '\n';

  return 0;
}

long long get_maximum_value(std::vector<Jewel> &jewels,
                            std::vector<int> &bags) {
  long long maximum_value = 0;

  std::sort(jewels.begin(), jewels.end(),
            [](const Jewel &x, const Jewel &y) { return x.weight < y.weight; });
  std::sort(bags.begin(), bags.end(),
            [](const int &x, const int &y) { return x < y; });

  std::priority_queue<int> priority_queue;
  int current_jewel_index = 0;

  for (int available_weight : bags) {
    while (current_jewel_index <= jewels.size() &&
           jewels[current_jewel_index].weight <= available_weight)
      priority_queue.push(jewels[current_jewel_index++].value);

    if (priority_queue.empty())
      continue;

    maximum_value += priority_queue.top();
    priority_queue.pop();
  }

  return maximum_value;
}
