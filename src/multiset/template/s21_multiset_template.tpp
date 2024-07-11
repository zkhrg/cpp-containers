#ifndef CPP2_S21_CONTAINERS_1_SRC_MULTISET_TEMPLATE_S21_MULTISET_TEMPLATE_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_MULTISET_TEMPLATE_S21_MULTISET_TEMPLATE_TPP_

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
// set member functions
template <typename T>
multiset<T>::multiset() {
  this->root = nullptr;
  this->len = 0;
}

template <typename T>
multiset<T>::multiset(std::initializer_list<value_type> const& items)
    : multiset() {
  for (auto it = items.begin(); it != items.end(); it++) this->innerInsert(*it);
}

template <typename T>
multiset<T>::multiset(const multiset& s) : multiset() {
  for (auto it = s.begin(); it != s.end(); it++) this->innerInsert(*it);
}

template <typename T>
typename std::pair<typename multiset<T>::iterator, bool> multiset<T>::insert(
    const T& value) {
  this->root = innerInsert(this->root, value, nullptr);
  typename set<T>::Node* current = this->innerSearch(this->root, value);

  return {iterator(current), true};
}

template <typename T>
typename set<T>::Node* multiset<T>::innerInsert(typename set<T>::Node* node,
                                                T value,
                                                typename set<T>::Node* parent) {
  if (node == nullptr) {
    ++(this->len);
    return new typename set<T>::Node(value, parent);
  }
  if (value < node->data) {
    node->left = innerInsert(node->left, value, node);
  } else if (value > node->data) {
    node->right = innerInsert(node->right, value, node);
  } else {
    ++(node->amount);
    ++(this->len);
    return node;
  }

  this->updateHeight(node);
  int balance = this->balanceFactor(node);

  // Left Left Case
  if (balance > 1 && value < node->left->data) {
    return this->rotateRight(node);
  }

  // Right Right Case
  if (balance < -1 && value > node->right->data) {
    return this->rotateLeft(node);
  }

  // Left Right Case
  if (balance > 1 && value > node->left->data) {
    node->left = this->rotateLeft(node->left);
    return this->rotateRight(node);
  }

  // Right Left Case
  if (balance < -1 && value < node->right->data) {
    node->right = this->rotateRight(node->right);
    return this->rotateLeft(node);
  }

  return node;
}

template <typename T>
void multiset<T>::innerInsert(T value) {
  this->root = this->innerInsert(this->root, value, nullptr);
}

template <typename T>
void multiset<T>::erase(iterator pos) {
  typename set<T>::Node* n = this->innerSearch(this->root, *pos);
  if (n->amount > 1) {
    --(n->amount);
    --(this->len);
    return;
  }
  this->root = this->innerRemove(this->root, *pos);
}

template <typename T>
multiset<T>& multiset<T>::operator=(const multiset& s) {
  if (this != &s) {
    multiset copy(s);
    *this = std::move(copy);
  }
  return *this;
}

template <typename T>
multiset<T>::multiset(multiset&& s) {
  this->root = s.root;
  this->len = s.len;
  s.root = nullptr;
  s.len = 0;
}

template <typename T>
multiset<T>& multiset<T>::operator=(multiset&& s) {
  if (this != &s) {
    this->clear(this->root);
    this->root = s.root;
    this->len = s.len;
    s.root = nullptr;
    s.len = 0;
  }
  return *this;
}

template <typename T>
void multiset<T>::merge(multiset& other) {
  for (const auto& elem : other) {
    this->insert(elem);
  }
}

template <typename T>
template <typename... Args>
std::vector<std::pair<typename s21::multiset<T>::iterator, bool>>
multiset<T>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> res;
  for (const auto& elem : {args...}) {
    res.push_back(this->insert(elem));
  }
  return res;
}

};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_MULTISET_TEMPLATE_S21_MULTISET_TEMPLATE_TPP_