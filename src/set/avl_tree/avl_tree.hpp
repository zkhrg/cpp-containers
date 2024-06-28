#pragma once

#include <iostream>

#include "avl_tree_node.hpp"

namespace s21 {
template <typename T>
class AVLTree {
 private:
  AVLTreeNode<T>* root;

  int height(AVLTreeNode<T>* AVLTreeNode) const;
  int balanceFactor(AVLTreeNode<T>* AVLTreeNode) const;
  void updateHeight(AVLTreeNode<T>* AVLTreeNode);

  AVLTreeNode<T>* rotateRight(AVLTreeNode<T>* y);
  AVLTreeNode<T>* rotateLeft(AVLTreeNode<T>* x);

  AVLTreeNode<T>* insert(AVLTreeNode<T>* AVLTreeNode, T value);
  AVLTreeNode<T>* search(AVLTreeNode<T>* AVLTreeNode, T value) const;
  void clear(AVLTreeNode<T>* AVLTreeNode);

 public:
  AVLTree();
  ~AVLTree();

  void insert(T value);
  AVLTreeNode<T>* search(T value) const;
};
}  // namespace s21

#include "avl_tree.tpp"
