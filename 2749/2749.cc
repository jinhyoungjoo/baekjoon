#include <iostream>

#define PISANO_PERIOD 1500000

int fibonnaci(long int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long int N = 0;
  std::cin >> N;

  std::cout << fibonnaci(N % PISANO_PERIOD) << '\n';
  return 0;
}

int fibonnaci(long int N) {
  if (N == 0 || N == 1)
    return N;

  int fib[3] = {0, 1, 1}, result = 0;
  for (long int i = 2; i <= N; i++) {
    result = (fib[1] + fib[2]) % 1000000;

    fib[0] = fib[1];
    fib[1] = fib[2];
    fib[2] = result;
  }
  return fib[1];
}
