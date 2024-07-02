#include <initializer_list>
#include <iostream>

namespace s21 {
// set member functions
template <typename T>
set<T>::set() : root(nullptr) {}

template <typename T>
set<T>::set(std::initializer_list<T> const& items) {
  for (auto it = items.begin(); it != items.end(); it++) insert(*it);
}

// template <typename T>
// set<T>::set(const set& s) {
//   for (const_iterator it = s.begin(); it != s.end(); it++) insert(*it);
// }

template <typename T>
set<T>::set(set&& s) : root(s.root) {
  s.root = nullptr;
}

template <typename T>
set<T>& set<T>::operator=(set&& s) {
  if (this != &s) {
    clear(root);
    root = s.root;
    s.root = nullptr;
  }
  return *this;
}

template <typename T>
set<T>::~set() {
  clear(root);
}

template <typename T>
int set<T>::height(set<T>::Node* node) const {
  return node ? node->height : 0;
}

template <typename T>
int set<T>::balanceFactor(set<T>::Node* node) const {
  return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
void set<T>::updateHeight(set<T>::Node* node) {
  node->height = 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
typename set<T>::Node* set<T>::rotateRight(set<T>::Node* y) {
  set<T>::Node* x = y->left;
  set<T>::Node* T2 = x->right;

  x->right = y;
  y->left = T2;

  updateHeight(y);
  updateHeight(x);

  return x;
}

template <typename T>
typename set<T>::Node* set<T>::rotateLeft(set<T>::Node* x) {
  set<T>::Node* y = x->right;
  set<T>::Node* T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

template <typename T>
void set<T>::insert(T value) {
  root = insert(root, value);
}

template <typename T>
typename set<T>::Node* set<T>::insert(set<T>::Node* node, T value) {
  if (node == nullptr) {
    return new set<T>::Node(value);
  }

  if (value < node->data) {
    node->left = insert(node->left, value);
  } else if (value > node->data) {
    node->right = insert(node->right, value);
  } else {
    return node;
  }

  updateHeight(node);

  int balance = balanceFactor(node);

  if (balance > 1 && value < node->left->data) {
    return rotateRight(node);
  }

  if (balance < -1 && value > node->right->data) {
    return rotateLeft(node);
  }

  if (balance > 1 && value > node->left->data) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  if (balance < -1 && value < node->right->data) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  return node;
}

template <typename T>
typename set<T>::Node* set<T>::search(T value) const {
  return search(root, value);
}

template <typename T>
typename set<T>::Node* set<T>::search(set<T>::Node* node, T value) const {
  if (node == nullptr || node->data == value) {
    return node;
  } else if (value < node->data) {
    return search(node->left, value);
  } else {
    return search(node->right, value);
  }
}

template <typename T>
bool set<T>::isEmpty() const {
  return root == nullptr;
}

template <typename T>
void set<T>::clear(set<T>::Node* node) {
  if (node != nullptr) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}
};  // namespace s21
