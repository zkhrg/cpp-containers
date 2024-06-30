#include <iostream>

#include "avl_tree/avl_tree.hpp"
#include "s21_set.hpp"

int main() {
  s21::AVLTree<int> bst;

  bst.insert(2);
  bst.insert(3);
  bst.insert(4);
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);
  bst.insert(8);
  bst.insert(123);
  bst.insert(124);
  bst.insert(125);
  bst.insert(126);
  bst.insert(127);
  bst.insert(128);
  bst.insert(129);
  bst.insert(130);
  bst.insert(131);

  int searchValue = 8;
  s21::AVLTree<int>::Node* result = bst.search(searchValue);
  if (result != nullptr) {
    std::cout << "found v: " << result->data << std::endl;
  } else {
    std::cout << "nf(((" << std::endl;
  }

  return 0;
}
