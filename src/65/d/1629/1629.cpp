#include <iostream>

long long get_solution(long long, long long, long long);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long A = 0, B = 0, C = 0;
  std::cin >> A >> B >> C;

  std::cout << get_solution(A, B, C) << '\n';

  return 0;
}

long long get_solution(long long A, long long B, long long C) {
  if (B == 0)
    return 1;

  if (B == 1)
    return A % C;

  long long subsolution = get_solution(A, B / 2, C) % C;
  subsolution = (subsolution * subsolution) % C;

  long long remainder = get_solution(A, B % 2, C) % C;
  return (subsolution * remainder) % C;
}
