#pragma once

namespace s21 {
template <typename T>
struct AVLTreeNode {
  T data;
  AVLTreeNode* left;
  AVLTreeNode* right;
  int height;

  AVLTreeNode(T value)
      : data(value), left(nullptr), right(nullptr), height(1) {}
};
}  // namespace s21
