#include <array>
#include <iostream>

#define MAX_INPUT_SIZE 12

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_testcases;
  std::cin >> num_testcases;

  std::array<int, MAX_INPUT_SIZE + 1> solutions;
  solutions[1] = 1;
  solutions[2] = 2;
  solutions[3] = 4;
  for (int i = 4; i <= MAX_INPUT_SIZE; i++)
    solutions[i] = solutions[i - 1] + solutions[i - 2] + solutions[i - 3];

  int input = 0;
  while (num_testcases--) {
    std::cin >> input;
    std::cout << solutions[input] << '\n';
  }

  return 0;
}
