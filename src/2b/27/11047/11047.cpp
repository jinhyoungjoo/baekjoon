#include <iostream>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, K;
  std::cin >> N >> K;

  std::vector<int> coins(N);
  for (int &coin : coins)
    std::cin >> coin;

  int num_coins = 0;
  for (auto it = coins.crbegin(); it != coins.crend(); it++) {
    int coin_value = *it;
    num_coins += (K / coin_value);
    K %= coin_value;
  }
  std::cout << num_coins << '\n';

  return 0;
}
