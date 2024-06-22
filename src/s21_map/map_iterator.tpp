namespace s21 {

// MapIterator============================================================

template <typename Key, typename T>
typename s21::map<Key, T>::reference
map<Key, T>::iterator::operator*() {
  return node->val;
}
template <typename Key, typename T>
typename s21::map<Key, T>::value_type*
map<Key, T>::iterator::operator->() {
  return &node->val;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator& 
map<Key, T>::iterator::operator++() {
  if(goRight()){
    while (goLeft());
  } else {
    while (!node->less && goParent());
    goParent();
  }
  return *this;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator 
map<Key, T>::iterator::operator++(int) {
  iterator res(node);
  ++*this;
  return res;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator& 
map<Key, T>::iterator::operator--() {
  if(goLeft()){
    while (goRight());
  } else {
    while (node->less && goParent());
    goParent();
  }
  return *this;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator 
map<Key, T>::iterator::operator--(int) {
  iterator res(node);
  --*this;
  return res;
}

template <typename Key, typename T>
bool map<Key, T>::iterator::operator==(iterator it) {
  return node == it.node;
}

template <typename Key, typename T>
bool map<Key, T>::iterator::operator!=(iterator it) {
  return node != it.node;
}

template <typename Key, typename T>
bool map<Key, T>::iterator::operator==(const_iterator it) {
  return node == it.node;
}

template <typename Key, typename T>
bool map<Key, T>::iterator::operator!=(const_iterator it) {
  return node != it.node;
}

// MapConstIterator=======================================================

template <typename Key, typename T>
typename s21::map<Key, T>::const_iterator&
map<Key, T>::const_iterator::operator=(const iterator& it) {
  this->node = it.node;
  return *this;
}

template <typename Key, typename T>
typename s21::map<Key, T>::const_reference&
map<Key, T>::const_iterator::operator*() const {
  return this->node->val;
}
template <typename Key, typename T>
const typename s21::map<Key, T>::value_type*
map<Key, T>::const_iterator::operator->() const {
  return &this->node->val;
}

// Map BinarTree Move=====================================================

template <typename Key, typename T>
bool s21::map<Key, T>::iterator::goLeft() {
  bool res = node->left != nullptr;
  if (res) node = node->left;
  return res; 
}

template <typename Key, typename T>
bool s21::map<Key, T>::iterator::goRight() {
  bool res = node->right != nullptr;
  if (res) node = node->right;
  return res; 
}

template <typename Key, typename T>
bool s21::map<Key, T>::iterator::goParent() {
  bool res = node->parent != nullptr;
  if (res) node = node->parent;
  return res; 
}

// Map Iterators==========================================================

template <typename Key, typename T>
typename s21::map<Key, T>::iterator 
map<Key, T>::begin() { return iterator(min_); }

template <typename Key, typename T>
typename s21::map<Key, T>::iterator 
map<Key, T>::end() { return iterator(max_); }

template <typename Key, typename T>
typename s21::map<Key, T>::const_iterator 
map<Key, T>::begin() const { return const_iterator(min_); }

template <typename Key, typename T>
typename s21::map<Key, T>::const_iterator 
map<Key, T>::end() const { return const_iterator(max_); }


};