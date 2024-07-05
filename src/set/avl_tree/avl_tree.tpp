#include <initializer_list>
#include <iostream>

namespace s21 {
// set member functions
template <typename T>
set<T>::set() : root(nullptr), len(0) {}

template <typename T>
set<T>::set(std::initializer_list<T> const& items) : root(nullptr) {
  for (auto it = items.begin(); it != items.end(); it++) innerInsert(*it);
}

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
int set<T>::height(Node* node) const {
  return node ? node->height : 0;
}

template <typename T>
int set<T>::balanceFactor(Node* node) const {
  return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
void set<T>::updateHeight(Node* node) {
  node->height = 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
typename set<T>::Node* set<T>::rotateRight(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  x->right = y;
  y->left = T2;

  if (T2) T2->parent = y;
  x->parent = y->parent;
  y->parent = x;

  updateHeight(y);
  updateHeight(x);

  return x;
}

template <typename T>
typename set<T>::Node* set<T>::rotateLeft(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  y->left = x;
  x->right = T2;

  if (T2) T2->parent = x;
  y->parent = x->parent;
  x->parent = y;

  updateHeight(x);
  updateHeight(y);

  return y;
}

template <typename T>
void set<T>::innerInsert(T value) {
  root = innerInsert(root, value, nullptr);
}

template <typename T>
typename set<T>::Node* set<T>::innerInsert(Node* node, T value, Node* parent) {
  if (node == nullptr) {
    ++len;
    return new Node(value, parent);
  }

  if (value < node->data) {
    node->left = innerInsert(node->left, value, node);
  } else if (value > node->data) {
    node->right = innerInsert(node->right, value, node);
  } else {
    return node;  // Duplicate values are not innerInserted
  }

  updateHeight(node);

  int balance = balanceFactor(node);

  // Left Left Case
  if (balance > 1 && value < node->left->data) {
    return rotateRight(node);
  }

  // Right Right Case
  if (balance < -1 && value > node->right->data) {
    return rotateLeft(node);
  }

  // Left Right Case
  if (balance > 1 && value > node->left->data) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  // Right Left Case
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
typename set<T>::Node* set<T>::search(Node* node, T value) const {
  if (node == nullptr || node->data == value) {
    return node;
  } else if (value < node->data) {
    return search(node->left, value);
  } else {
    return search(node->right, value);
  }
}

template <typename T>
bool set<T>::empty() const {
  return root == nullptr;
}

template <typename T>
void set<T>::clear() {
  clear(root);
}

template <typename T>
typename set<T>::size_type set<T>::size() {
  return len;
}

template <typename T>
typename set<T>::size_type set<T>::max_size() {
  return MAX_MEMORY / sizeof(set<T>::Node);
}

template <typename T>
void set<T>::clear(Node* node) {
  if (node != nullptr) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

template <typename T>
std::pair<typename set<T>::iterator, bool> set<T>::insert(
    const_reference value) {
  typename set<T>::size_type lc = this->size();
  root = innerInsert(root, value, nullptr);
  bool r = true;
  if (lc - this->size() == 0) r = false;
  Node* current = search(root, value);

  return {iterator(current), r};
}

template <typename T>
typename set<T>::iterator set<T>::begin() {
  typename set<T>::Node* current = root;
  while (current && current->left) {
    current = current->left;
  }
  return set<T>::iterator(current);
}
};  // namespace s21
