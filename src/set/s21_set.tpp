#include <iostream>

namespace s21 {

// Set Member functions
template <typename T>
set<T>::set()
    : size_{},
      fake_{false, &fake_, &fake_, &fake_, {}},
      top_{fake_.left},
      min_{fake_.right},
      max_(&fake_) {}

template <typename T>
set<T>::set(std::initializer_list<value_type> const& items) : set() {
  for (auto it = items.begin(); it != items.end(); it++) insert(*it);
}

template <typename T>
set<T>::set(const set<T>& s) : set() {
  for (const_iterator it = s.begin(); it != s.end(); it++) insert(*it);
}

template <typename T>
set<T>::set(set<T>&& s) : set() {
  if (!s.empty()) {
    top_ = s.top_;
    top_->parent = fake_.parent;
    min_ = s.min_;
    max_ = s.max_;
    s.top_ = s.min_ = s.max_ = s.fake_.parent;
    size_ = s.size_;
    s.size_ = 0;
  }
}

template <typename T>
typename s21::set<T>& set<T>::operator=(set<T>&& s) {
  if (this != &s) {
    clear();
    fake_ = s.fake_;
    max_ = s.max_;
    s.top_ = s.min_ = s.max_ = &s.fake_;
    size_ = s.size_;
    s.size_ = 0;
  }
  return *this;
}

template <typename T>
set<T>::~set() {
  clear();
}

// Set Capacity
template <typename T>
bool set<T>::empty() {
  return min_ == &fake_;
}

// Set Modifiers
// rewrite
template <typename T>
void set<T>::clear() {
  while (!empty()) {
    iterator it = begin();
    iterator loss(it++);
    min_ = it.node;
    if (loss.node->parent == min_) {
      min_->left = nullptr;
      loss.node->parent = nullptr;
      delete loss.node;
    } else {
      loss.node->parent->left = loss.node->right;
      loss.node->right->parent = loss.node->parent;
      loss.node->right->less = true;
      loss.node->parent = nullptr;
      loss.node->right = nullptr;
      delete loss.node;
    }
  }
  max_ = top_ = min_;
  size_ = 0;
}

// TODO: rewrite tak ne dolzhno bit
template <typename T>
std::pair<typename s21::set<T>::iterator, bool> set<T>::insert(
    const value_type& value) {}

};  // namespace s21