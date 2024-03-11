#include <iostream>
#include <memory>
#include <vector>

#define MAX_ELEMENTS 26

enum TRAVERSAL_MODE { PREORDER, INORDER, POSTORDER };

class Node {
public:
  Node(char root) : root_(root), left_(nullptr), right_(nullptr) {}

  void set_left(std::shared_ptr<Node> node) { left_ = node; }
  void set_right(std::shared_ptr<Node> node) { right_ = node; }

  void print_traversal(TRAVERSAL_MODE);

private:
  char root_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N = 0;
  std::cin >> N;
  std::vector<std::shared_ptr<Node>> tree;
  for (char ch = 'A'; ch < char('A' + N); ch++)
    tree.emplace_back(std::make_shared<Node>(ch));

  char root, left, right;
  for (int i = 0; i < N; i++) {
    std::cin >> root >> left >> right;

    auto node = tree[root - 'A'];

    if (left != '.')
      node->set_left(tree[left - 'A']);

    if (right != '.')
      node->set_right(tree[right - 'A']);
  }

  tree[0]->print_traversal(PREORDER);
  std::cout << '\n';
  tree[0]->print_traversal(INORDER);
  std::cout << '\n';
  tree[0]->print_traversal(POSTORDER);
  std::cout << '\n';

  return 0;
}

void Node::print_traversal(TRAVERSAL_MODE mode) {
  if (mode == PREORDER) {
    std::cout << root_;

    if (left_ != nullptr)
      left_->print_traversal(mode);

    if (right_ != nullptr)
      right_->print_traversal(mode);

  } else if (mode == INORDER) {
    if (left_ != nullptr)
      left_->print_traversal(mode);

    std::cout << root_;

    if (right_ != nullptr)
      right_->print_traversal(mode);

  } else if (mode == POSTORDER) {
    if (left_ != nullptr)
      left_->print_traversal(mode);

    if (right_ != nullptr)
      right_->print_traversal(mode);

    std::cout << root_;
  }
}
