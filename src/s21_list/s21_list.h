#ifndef S21_LIST
#define S21_LIST

#include <initializer_list>
#include <iostream>

#include "../utils/utils.h"

using s21_utils::ListConstIterator;
using s21_utils::ListIterator;
using s21_utils::Node;

namespace s21 {
template <class T>
class s21_list {
 private:
  Node<T>* start;
  Node<T>* finish;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  s21_list();
  s21_list(size_type n);
  s21_list(std::initializer_list<value_type> const& items);
  s21_list(const s21_list& l);
  s21_list(s21_list&& l);
  ~s21_list();

  void push_back(const_reference val);

  iterator begin() { return iterator(start); };
  iterator end() { return iterator(finish); };
  const_iterator begin() const { return const_iterator(start); }
  const_iterator end() const { return const_iterator(finish); }
};

};  // namespace s21

#include "s21_list.tpp"

#endif