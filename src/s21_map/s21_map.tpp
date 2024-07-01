#include <iostream>

namespace s21 {

// Map Member functions
template <typename Key, typename T>
map<Key, T>::map()
    : size_{},
      fake_{false, nullptr, nullptr, &fake_, {}},
      top_{fake_.left},
      min_{fake_.right}, 
      end_{&fake_} {}

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
  *this = std::move(m);
}

template <typename Key, typename T>
typename s21::map<Key, T>& map<Key, T>::operator=(map<Key, T>&& m) {
  if (this != &m) {
    clear();
    if(!m.empty()) {
      top_ = m.top_;
      top_->parent = &fake_;
      min_ = m.min_;
      m.top_ = nullptr;
      m.min_ = m.end_;
      size_ = m.size_;
      m.size_ = 0;
    }
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
  return min_ == end_;
}

// Map Modifiers
template <typename Key, typename T>
void map<Key, T>::clear() {
  while (!empty()) {
    erase(begin());
  }
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
    top_ = new Node{true, min_, nullptr, nullptr, value};
    min_ = top_;
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
      it.goLeft();
    } else if (it->first < key) {
      it.node->right = new Node{false, it.node, 0, 0, value};
      it.goRight();
    } else {
      res.second = false;
    }
  }
  if (res.second) size_++;
  return res;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator map<Key, T>::erase(iterator pos) {
  iterator top = pos, left = pos, right = pos, res = pos;
  res++;
  top.goParent();
  left.goLeft();
  right.goRight();
  if(pos == left && pos == right) {
    (pos.node->less ? top.node->left : top.node->right) = nullptr;
  } else if (pos != right) {
    (pos.node->less ? top.node->left : top.node->right) = right.node;
    right.node->parent = top.node;
    right.node->less = pos.node->less;
  } else {
    (pos.node->less ? top.node->left : top.node->right) = left.node;
    left.node->parent = top.node;
    left.node->less = pos.node->less;
  }
  if (pos != left && pos != right) {
    while (right.goLeft());
    right.node->left = left.node;
    left.node->parent = right.node;
  } 
  if (pos == begin()) min_ = res.node;
  pos.node->left = pos.node->right = pos.node->parent = nullptr;
  delete pos.node;
  size_--;
  return res;
}

template <typename Key, typename T>
void map<Key, T>::swap(map<Key, T>& other) {
  map buff;
  if(this != &other) {
    buff = std::move(other);
    other = std::move(*this);
    *this = std::move(buff);
  }
}
template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  if(this == &other || other.empty()) return;
  if(empty()) {
    *this = std::move(other);
  } else {
    for(auto it = other.begin(); it != other.end(); it++) {
      while(it != other.end() && insert(*it)->second)
        it = other.erase(it);
    }
  }
}

template <typename Key, typename T>
template <typename... Args>
std::vector<std::pair<typename s21::map<Key,T>::iterator,bool>> map<Key,T>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator,bool>> res;
  for(const auto& elem : {args...}) {
    res.push_back(insert(elem));
  }
  return res;
}

// Map Lookup
template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) {
  if(empty()) return false;
  iterator it(top_);
  for (bool flag = true; it->first != key && flag;) {
    while (it->first < key && flag) flag = it.goRight();
    while (it->first > key && flag) flag = it.goLeft();
  }
  return it->first == key;
}

};  // namespace s21