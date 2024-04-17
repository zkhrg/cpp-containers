#ifndef S21_LIST
#define S21_LIST

#include <initializer_list>
#include <iostream>

namespace s21 {

// container of list

template <typename tmp>
struct Node {
  Node<tmp>*next, *back;
  tmp arg;
};

// iterator

template <typename T>
class ListIterator {
 private:
  Node<T>* node;

 public:
  ListIterator(Node<T>*& other) : node(other){};

  ~ListIterator(){};

  T& operator*() { return node->arg; }
  ListIterator& operator++();
  ListIterator& operator--();
  ListIterator&& operator++(int);
  ListIterator&& operator--(int);
  bool operator!=(ListIterator<T> it) noexcept { return node != it.node; };
};

template <typename tmp>
typename s21::ListIterator<tmp>& ListIterator<tmp>::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21::ListIterator<tmp>& ListIterator<tmp>::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21::ListIterator<tmp>&& ListIterator<tmp>::operator++(int) {
  ListIterator<tmp> out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21::ListIterator<tmp>&& ListIterator<tmp>::operator--(int) {
  ListIterator<tmp> out(*this);
  this->node = this->node->back;
  return out;
}

// template <typename T>
// class ListConstIterator : public ListIterator<T> {
//
// };

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
  // using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  s21_list();
  s21_list(size_type n);
  s21_list(std::initializer_list<value_type> const& items);
  s21_list(const s21_list& l);
  s21_list(s21_list&& l);
  ~s21_list();

  void push_back(const_reference val);

  iterator begin() { return iterator{start}; };
  iterator end() { return iterator(finish); };
};

template <typename tmp>
s21_list<tmp>::s21_list() {
  Node<value_type>* end = new Node<value_type>{value_type{}};
  start = finish = end;
}

template <typename tmp>
s21_list<tmp>::s21_list(size_type n) : s21_list<tmp>::s21_list() {
  value_type def{};
  for (size_type i = 0; i < n; i++) {
    push_back(def);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(std::initializer_list<value_type> const& items)
    : s21_list<tmp>::s21_list() {
  for (auto it = items.begin(); it != items.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(const s21_list<tmp>& list) : s21_list<tmp>::s21_list() {
  for (iterator it = list.begin(); it != list.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(s21_list<tmp>&& list)
    : start(list.start), finish(list.finish) {
  list.start = nullptr;
  list.finish = nullptr;
}

template <typename tmp>
s21_list<tmp>::~s21_list() {
  for (; start != finish; start = start->next) {
    delete start->back;
  }
  delete finish;
}
// funcs

template <typename tmp>
void s21_list<tmp>::push_back(const_reference val) {
  Node<value_type>* ptr = finish->back;
  Node<value_type>* nd = new Node<value_type>;
  nd->arg = val;
  if (ptr) {
    ptr->next = nd;
    nd->back = ptr;
  } else {
    start = nd;
  }
  nd->next = finish;
  finish->back = nd;
}

};  // namespace s21

#endif