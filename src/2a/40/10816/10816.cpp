#include <iostream>
#include <unordered_map>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map<int, int> hashmap;

  int N = 0;
  std::cin >> N;

  int number = 0;
  while (N--) {
    std::cin >> number;

    if (hashmap.find(number) == hashmap.end())
      hashmap[number] = 1;
    else
      hashmap[number]++;
  }

  int M = 0;
  std::cin >> M;

  while (M--) {
    std::cin >> number;

    if (hashmap.find(number) == hashmap.end())
      std::cout << "0 ";
    else
      std::cout << hashmap[number] << ' ';
  }
  std::cout << '\n';

  return 0;
}
