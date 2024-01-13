#include <iostream>
#include <queue>

class MiddleList {
public:
  void insert(int input) {
    if (this->left_queue.size() + this->right_queue.size() == 0) {
      this->left_queue.push(input);
      return;
    }

    input >= this->left_queue.top() ? this->right_queue.push(input)
                                    : this->left_queue.push(input);

    this->balance();
  }

  void balance() {
    int difference = this->left_queue.size() - this->right_queue.size();

    if (difference == 2) {
      int target = this->left_queue.top();
      this->left_queue.pop();
      this->right_queue.push(target);
    } else if (difference == -1) {
      int target = this->right_queue.top();
      this->right_queue.pop();
      this->left_queue.push(target);
    }
  }

  int get_middle() { return this->left_queue.top(); }

private:
  std::priority_queue<int> left_queue;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right_queue;
};

int main(int argc, const char **argv) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  MiddleList list = MiddleList();

  int N = 0, input = 0;
  std::cin >> N;
  while (N--) {
    std::cin >> input;
    list.insert(input);
    std::cout << list.get_middle() << '\n';
  }
  return 0;
}
