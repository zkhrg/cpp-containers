#include <iostream>

namespace s21 {

// Map Member functions
template <typename Key, typename T>
map<Key, T>::map()
    : size_{},
      fake_{false, &fake_, &fake_, &fake_, {}},
      top_{fake_.left},
      min_{fake_.right},
      max_(&fake_) {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) : map() {
  for (auto it = items.begin(); it != items.end(); it++) insert(*it);
}

template <typename Key, typename T>
map<Key, T>::map(const map<Key, T>& m) : map() {
  for (const_iterator it = m.begin(); it != m.end(); it++) insert(*it);
}

template <typename Key, typename T>
map<Key, T>::map(map<Key, T>&& m) : map() {
  if (!m.empty()){
    top_ = m.top_;
    top_->parent = fake_.parent;
    min_ = m.min_;
    max_ = m.max_;
    m.top_ = m.min_ = m.max_ = m.fake_.parent;
    size_ = m.size_;
    m.size_ = 0;
  }
}

template <typename Key, typename T>
typename s21::map<Key, T>& map<Key, T>::operator=(map<Key, T>&& m) {
  if (this != &m) {
    clear();
    fake_ = m.fake_;
    max_ = m.max_;
    m.top_ = m.min_ = m.max_ = &m.fake_;
    size_ = m.size_;
    m.size_ = 0;
  }
  return *this;
}

template <typename Key, typename T>
map<Key, T>::~map() {
  clear();
}

// Map Element access
template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  if(empty())
    throw std::out_of_range("Map is empty\n");
  iterator it = end();
  it.goLeft();
  for (bool flag = true; it->first != key && flag;) {
    while (it->first < key && flag) flag = it.goRight();
    while (it->first > key && flag) flag = it.goLeft();
  }
  if (it->first != key)
    throw std::out_of_range("Value doesn't exist\n");
  return it->second;
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return insert(key, {}).first->second;
}

// Map Capacity
template <typename Key, typename T>
bool map<Key, T>::empty() {
  return min_ == &fake_;
}

// Map Modifiers
template <typename Key, typename T>
void map<Key, T>::clear() {
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

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  return insert({key, obj});
}

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool>
map<Key, T>::insert_or_assign(const Key& key, const T& obj) {
  auto res = insert({key, obj});
  if (!res.second) res.first->second = obj;
  return res;
}

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  std::pair<iterator, bool> res{end(), true};
  iterator& it = res.first;
  const Key& key = value.first;
  if (empty()) {
    top_ = new Node{true, max_, nullptr, nullptr, value};
    min_ = max_ = top_;
    it.goLeft();
  } else {
    it.goLeft();
    for (bool flag = true; it->first != key && flag;) {
      while (it->first < key && flag) flag = it.goRight();
      while (it->first > key && flag) flag = it.goLeft();
    }
    if (it->first > key) {
      it.node->left = new Node{true, it.node, 0, 0, value};
      if (min_->left) min_ = min_->left;
    } else if (it->first < key) {
      it.node->right = new Node{false, it.node, 0, 0, value};
      if (max_->right) max_ = max_->right;
    } else {
      res.second = false;
    }
  }
  if (res.second) size_++;
  return res;
}

};  // namespace s21