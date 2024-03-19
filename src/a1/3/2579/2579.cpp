#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int get_maximum_score(const std::vector<int> &);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;

  std::vector<int> scores(N);
  for (int &score : scores)
    std::cin >> score;

  std::cout << get_maximum_score(scores) << '\n';

  return 0;
}

int get_maximum_score(const std::vector<int> &scores) {
  std::vector<std::array<int, 2>> score_table(scores.size());

  switch (score_table.size()) {
  case 1:
    return scores[0];
  case 2:
    return scores[0] + scores[1];
  case 3:
    return std::max(scores[0], scores[1]) + scores[2];
  default:
    break;
  }

  score_table[1] = {scores[1], scores[0] + scores[1]};
  score_table[2] = {scores[0] + scores[2], scores[1] + scores[2]};

  for (int i = 3; i < score_table.size(); i++) {
    score_table[i] = {
        scores[i] + std::max(score_table[i - 2][0], score_table[i - 2][1]),
        scores[i] + score_table[i - 1][0]};
  }

  return std::max(score_table[score_table.size() - 1][0],
                  score_table[score_table.size() - 1][1]);
}
