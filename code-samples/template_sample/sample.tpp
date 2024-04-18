#include <iostream>

template <typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
SNode<T>::~SNode() {
  if (next) delete next;
  if (back) delete back;
  std::cout << arg << std::endl;
}