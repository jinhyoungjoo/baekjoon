#include <iostream>

long long get_count(int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::cout << get_count(N) << '\n';

  return 0;
}

long long get_count(int target_length) {
  long long num_cases_with_trailing_zero = 0, num_cases_with_trailing_one = 1;

  for (int i = 1; i < target_length; i++) {
    long long current_zero_value = num_cases_with_trailing_zero;

    num_cases_with_trailing_zero += num_cases_with_trailing_one;
    num_cases_with_trailing_one = current_zero_value;
  }

  return num_cases_with_trailing_zero + num_cases_with_trailing_one;
}
