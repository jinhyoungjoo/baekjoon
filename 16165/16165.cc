#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map<std::string, std::string> member_to_team;
  std::unordered_map<std::string, std::vector<std::string>> team_to_member;

  int N = 0, M = 0;
  std::cin >> N >> M;

  int num_members = 0;
  std::string team_name = "", member_name = "";
  while (N--) {
    std::cin >> team_name >> num_members;

    std::vector<std::string> members(num_members);
    for (int i = 0; i < num_members; i++) {
      std::cin >> member_name;
      members[i] = member_name;
      member_to_team[member_name] = team_name;
    }

    std::sort(members.begin(), members.end());
    team_to_member[team_name] = members;
  }

  int command = 0;
  std::string input = "";
  while (M--) {
    std::cin >> input >> command;
    if (command == 1) {
      std::cout << member_to_team[input] << '\n';
    } else {
      for (auto &name : team_to_member[input])
        std::cout << name << '\n';
    }
  }

  return 0;
}
