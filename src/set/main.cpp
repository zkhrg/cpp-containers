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
  // s21::set<int> s1(s);

  int searchValue = 192;
  // std::cout << s.root->left->data << std::endl;
  s21::set<int>::Node* result = s1.search(searchValue);
  if (result != nullptr) {
    std::cout << "found v: " << result->parent->data << std::endl;
  } else {
    std::cout << "nf(((" << std::endl;
  }
  std::cout << (s.root == nullptr) << std::endl;

  s21::set<int> mySet;
  mySet.insert(5);
  mySet.insert(20);
  mySet.insert(10);

  auto it = mySet.begin();
  ++it;
  // it != mySet.end();
  // std::cout << it.node->data << std::endl;
  // for ( it != mySet.end(); it++) {
  // std::cout << *it << " ";
  // }

  return 0;
}
