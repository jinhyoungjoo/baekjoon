#include <algorithm>
#include <iostream>
#include <vector>

struct Item {
  int weight;
  int value;
};

int get_maximum_value(const std::vector<Item> &, int, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, K = 0;
  std::cin >> N >> K;

  std::vector<Item> items(N);
  for (Item &item : items)
    std::cin >> item.weight >> item.value;

  std::cout << get_maximum_value(items, N, K) << '\n';

  return 0;
}

int get_maximum_value(const std::vector<Item> &items, int num_items,
                      int max_weight) {
  std::vector<int> max_value_table(max_weight + 1, 0);
  std::vector<int> previous_line(max_weight + 1, 0);

  for (int item = 0; item < num_items; item++) {
    for (int weight = 0; weight <= max_weight; weight++) {
      if (weight < items[item].weight)
        continue;

      max_value_table[weight] = std::max(
          previous_line[weight],
          previous_line[weight - items[item].weight] + items[item].value);
    }

    for (int weight = 0; weight <= max_weight; weight++)
      previous_line[weight] = max_value_table[weight];
  }

  return max_value_table[max_weight];
}
