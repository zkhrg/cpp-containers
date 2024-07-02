namespace s21 {

// BaseIterator===========================================================

template <typename T>
template <class Iter>
Iter set<T>::BaseIterator<Iter>::operator++() {
  if (goRight()) {
    while (goLeft());
  } else {
    while (!node->less && goParent());
    goParent();
  }
  Iter res(node);
  return res;
}

template <typename T>
template <class Iter>
Iter set<T>::BaseIterator<Iter>::operator++(int) {
  Iter res(node);
  ++*this;
  return res;
}

template <typename T>
template <class Iter>
Iter set<T>::BaseIterator<Iter>::operator--() {
  if (goLeft()) {
    while (goRight());
  } else {
    while (node->less && goParent());
    goParent();
  }
  Iter res(node);
  return res;
}

template <typename T>
template <class Iter>
Iter set<T>::BaseIterator<Iter>::operator--(int) {
  Iter res(node);
  --*this;
  return res;
}

template <typename T>
template <class Iter>
bool s21::set<T>::BaseIterator<Iter>::goLeft() {
  bool res = node->left != nullptr;
  if (res) node = node->left;
  return res;
}

template <typename T>
template <class Iter>
bool s21::set<T>::BaseIterator<Iter>::goRight() {
  bool res = node->right != nullptr;
  if (res) node = node->right;
  return res;
}

template <typename T>
template <class Iter>
bool s21::set<T>::BaseIterator<Iter>::goParent() {
  bool res = node->parent != nullptr;
  if (res) node = node->parent;
  return res;
}

// setIterator============================================================

template <typename T>
typename s21::set<T>::reference set<T>::iterator::operator*() {
  return this->node->val;
}
template <typename T>
typename s21::set<T>::value_type* set<T>::iterator::operator->() {
  return &this->node->val;
}

// setConstIterator=======================================================

template <typename T>
typename s21::set<T>::const_iterator& set<T>::const_iterator::operator=(
    const iterator& it) const {
  this->node = it.node;
  return *this;
}

template <typename T>
typename s21::set<T>::const_reference& set<T>::const_iterator::operator*()
    const {
  return this->node->val;
}
template <typename T>
const typename s21::set<T>::value_type* set<T>::const_iterator::operator->()
    const {
  return &this->node->val;
}

};  // namespace s21