#include <functional>
#include <iostream>
#include <map>
#include <string>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::string name, log_type;
  std::map<std::string, bool, std::greater<std::string>> map;

  while (N--) {
    std::cin >> name >> log_type;

    map[name] = (log_type == "enter");
  }

  for (const auto &[name, is_here] : map) {
    if (!is_here)
      continue;

    std::cout << name << '\n';
  }

  return 0;
}
