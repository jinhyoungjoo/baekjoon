#include <iostream>
#include <stack>

void execute_command(std::stack<int> &, int);

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  int command = 0;
  std::stack<int> stack;
  while (N--) {
    std::cin >> command;
    execute_command(stack, command);
  }
  return 0;
}

void execute_command(std::stack<int> &stack, int command) {
  if (command == 1) {
    int integer = 0;
    std::cin >> integer;
    stack.push(integer);
    return;
  }

  if (command == 2) {
    std::cout << (stack.empty() ? -1 : stack.top()) << '\n';
    if (!stack.empty())
      stack.pop();
    return;
  }

  switch (command) {
  case 3:
    std::cout << stack.size() << '\n';
    break;

  case 4:
    std::cout << (stack.empty() ? 1 : 0) << '\n';
    break;

  case 5:
    std::cout << (stack.empty() ? -1 : stack.top()) << '\n';
    break;

  default:
    break;
  }
}
