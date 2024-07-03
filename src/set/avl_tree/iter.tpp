namespace s21 {

// BaseIterator===========================================================
// template <typename T>
// typename set<T>::Node* findPrev(typename set<T>::Node* node) {
//   if (node->left) {
//     node = node->left;
//     while (node->right) {
//       node = node->right;
//     }
//     return node;
//   }

//   while (node->parent && node == node->parent->left) {
//     node = node->parent;
//   }

//   return node->parent;
// }

template <typename T>
template <class Iter>
typename set<T>::Node* s21::set<T>::BaseIterator<Iter>::findNext(
    typename set<T>::Node* z) {
  if (z->right) {
    z = z->right;
    while (z->left) {
      z = z->left;
    }
    return z;
  }

  while (z->parent && z == z->parent->right) {
    z = z->parent;
  }

  return z->parent;
}

template <typename T>
template <class Iter>
void s21::set<T>::BaseIterator<Iter>::operator++() {
  std::cout << findNext(findNext(node))->data << std::endl;
  // Iter res(nullptr);
  // return res;
}

// template <typename T>
// template <class Iter>
// Iter set<T>::BaseIterator<Iter>::operator++(int) {
//   Iter res(node);
//   ++*this;
//   return res;
// }

// template <typename T>
// template <class Iter>
// Iter set<T>::BaseIterator<Iter>::operator--() {
//   if (goLeft()) {
//     while (goRight());
//   } else {
//     while (node->less && goParent());
//     goParent();
//   }
//   Iter res(node);
//   return res;
// }

// template <typename T>
// template <class Iter>
// Iter set<T>::BaseIterator<Iter>::operator--(int) {
//   Iter res(node);
//   --*this;
//   return res;
// }

// setIterator============================================================

// template <typename T>
// typename s21::set<T>::reference set<T>::iterator::operator*() {
//   return this->node->data;
// }
// template <typename T>
// typename s21::set<T>::value_type* set<T>::iterator::operator->() {
//   return &this->node->data;
// }

// setConstIterator=======================================================

// template <typename T>
// typename s21::set<T>::const_iterator& set<T>::const_iterator::operator=(
//     const iterator& it) const {
//   this->node = it.node;
//   return *this;
// }

// template <typename T>
// typename s21::set<T>::const_reference& set<T>::const_iterator::operator*()
//     const {
//   return this->node->val;
// }
// template <typename T>
// const typename s21::set<T>::value_type* set<T>::const_iterator::operator->()
//     const {
//   return &this->node->val;
// }
};  // namespace s21