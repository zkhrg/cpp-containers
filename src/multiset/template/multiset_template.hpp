#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
typename std::pair<typename multiset<T>::iterator, bool> multiset<T>::insert(
    const T& value) {
  this->root = innerInsert(this->root, value, nullptr);
  Node* current = this->innerSearch(this->root, value);

  return {iterator(current), true};
}

template <typename T>
typename multiset<T>::Node* multiset<T>::innerInsert(Node* n, T value,
                                                     Node* p) {
  std::cout << "Init" << std::endl;
}

template <typename T>
typename multiset<T>::Node* multiset<T>::innerRemove(Node* m, T value) {
  std::cout << "Init" << std::endl;
}
template <typename T>
void multiset<T>::innerInsert(T value) {
  std::cout << "Init" << std::endl;
}
};  // namespace s21
