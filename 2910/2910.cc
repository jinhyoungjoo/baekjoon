#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using Item = std::tuple<int, int, int>;

void get_input(std::map<int, Item> &, int);
void print_result(std::map<int, Item> &);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0, C = 0;
  std::cin >> N >> C;

  std::map<int, Item> map;
  get_input(map, N);
  print_result(map);

  return 0;
}

void get_input(std::map<int, Item> &map, int N) {
  int input;
  for (int i = 0; i < N; i++) {
    std::cin >> input;

    if (map.count(input) == 0)
      map[input] = {input, i, 1};
    else
      std::get<2>(map[input]) += 1;
  }
}

void print_result(std::map<int, Item> &map) {
  std::vector<Item> list;
  for (const auto &[_, value] : map)
    list.emplace_back(value);

  std::sort(list.begin(), list.end(), [](const Item &item1, const Item &item2) {
    int freq1 = std::get<2>(item1), freq2 = std::get<2>(item2);
    if (freq1 != freq2)
      return freq1 > freq2;

    return std::get<1>(item1) < std::get<1>(item2);
  });

  for (auto &[item, _, frequency] : list) {
    while (frequency--)
      std::cout << item << ' ';
  }
  std::cout << '\n';
}
