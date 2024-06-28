#include <iostream>

#include "avl_tree/avl_tree.hpp"

int main() {
  s21::AVLTree<int> bst;

  bst.insert(2);
  bst.insert(3);
  bst.insert(4);
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);
  bst.insert(8);

  int searchValue = 7;
  s21::AVLTreeNode<int>* result = bst.search(searchValue);
  if (result != nullptr) {
    std::cout << "found v: " << result->data << std::endl;
  } else {
    std::cout << "nf(((" << std::endl;
  }

  return 0;
}
