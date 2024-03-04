#include <algorithm>
#include <iostream>

#define MAX_ELEMENTS 1000

class Primes {
public:
  Primes();
  bool is_prime(int);

private:
  std::array<bool, MAX_ELEMENTS + 1> is_prime_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  Primes primes = Primes();
  int target = 0, num_primes = 0;
  while (N--) {
    std::cin >> target;

    if (primes.is_prime(target))
      num_primes++;
  }
  std::cout << num_primes << '\n';

  return 0;
}

Primes::Primes() {
  std::fill(is_prime_.begin(), is_prime_.end(), true);

  is_prime_[1] = false;
  for (int i = 2; i < is_prime_.size(); i++) {
    if (!is_prime_[i])
      continue;

    for (int j = (i + i); j < is_prime_.size(); j += i)
      is_prime_[j] = false;
  }
}

bool Primes::is_prime(int target) {
  if (target < 1 || target > MAX_ELEMENTS)
    return false;

  return is_prime_[target];
}
