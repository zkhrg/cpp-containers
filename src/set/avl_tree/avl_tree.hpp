#pragma once  // rewrite

#include <iostream>

namespace s21 {
template <typename T>
class AVLTree {
 public:
  typedef struct Node {
    T data;
    Node* left;
    Node* right;
    int height;

    Node(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
  } Node;

 private:
  Node* root;

  int height(Node* n) const;
  int balanceFactor(Node* n) const;
  void updateHeight(Node* n);

  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);

  Node* insert(Node* n, T value);
  Node* search(Node* n, T value) const;
  void clear(Node* n);

 public:
  AVLTree();
  ~AVLTree();

  void insert(T value);
  Node* search(T value) const;
};
}  // namespace s21

#include "avl_tree.tpp"
