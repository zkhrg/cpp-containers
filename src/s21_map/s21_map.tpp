#include <iostream>

namespace s21 {

// Map Member functions
template <typename Key, typename T>
map<Key, T>::map(): size_{}, fake_{}, min_{&fake_}, max_(&fake_) {}

template <typename Key, typename T>
map<Key, T>::~map() {
  clear();
}


// Map Capacity
template <typename Key, typename T>
bool map<Key, T>::empty() { return max_ == min_; }

// Map Modifiers
template <typename Key, typename T>
void map<Key, T>::clear(){
  while(!empty()){
    iterator it = begin();
    iterator loss(it++);
    min_ = it.node;
    if(loss.node->parent == min_) {
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
}

template <typename Key, typename T>
std::pair<typename s21::map<Key, T>::iterator, bool>
map<Key, T>::insert(const Key& key, const T& obj){
  std::pair<iterator, bool> res{end(), true};
  if(empty()) {
    max_->left = new Node{true, max_, nullptr, nullptr, value_type{key, obj}};
    min_ = max_->right = max_->left;
    res.first.goLeft();
  } else {
    res.first.goLeft();
    for (bool flag = true; res.first.node->val.first != key && flag;) {
      while(res.first.node->val.first < key && flag) flag = res.first.goRight();
      while(res.first.node->val.first > key && flag) flag = res.first.goLeft();
    }
    if (res.first.node->val.first < key) {
      res.first.node->left = new Node{true, res.first.node, nullptr, nullptr, value_type{key, obj}};
      if(min_->left) min_ = max_->right = min_->left;
    } else if (res.first.node->val.first > key) {
      res.first.node->right = new Node{false, res.first.node, nullptr, nullptr, value_type{key, obj}};
    } else {
      res.second = false;
    }
  }
  return res;
}

};