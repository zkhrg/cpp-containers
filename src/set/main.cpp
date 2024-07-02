#include <iostream>

#include "avl_tree/avl_tree.hpp"
// #include "s21_set.hpp"

int main() {
  // s21::set<int> s1;
  // s1.insert(3);
  // s1.insert(4);
  // s1.insert(5);
  // s1.insert(6);
  // std::cout << s1.root->data << std::endl;
  s21::set<int> s{3, 4, 5, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 192};
  s21::set<int> s1(std::move(s));

  int searchValue = 192;
  // std::cout << s.root->left->data << std::endl;
  s21::set<int>::Node* result = s1.search(searchValue);
  if (result != nullptr) {
    std::cout << "found v: " << result->data << std::endl;
  } else {
    std::cout << "nf(((" << std::endl;
  }
  std::cout << (s.root == nullptr) << std::endl;

  return 0;
}
