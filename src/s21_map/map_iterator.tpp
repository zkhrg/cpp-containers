namespace s21 {

// MapIterator============================================================

template <typename Key, typename T>
typename s21::map<Key, T>::reference
map<Key, T>::iterator::operator*() {
  return node->val;
}

template <typename Key, typename T>
typename s21::map<Key, T>::iterator& 
map<Key, T>::iterator::operator++() {
  if(node->right){
    node = node->right;
    while (node->left) node = nade->left;
  } else {
    while (!node->less) node = node->parent;
    node = node->parent;
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
  if(node->left){
    node = node->left;
    while (node->right) node = nade->right;
  } else {
    while (node->less) node = node->parent;
    node = node->parent;
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
  node = it.node;
  return *this;
}

template <typename Key, typename T>
typename s21::map<Key, T>::const_reference&
map<Key, T>::const_iterator::operator*() const {
  return node->val;
}

};