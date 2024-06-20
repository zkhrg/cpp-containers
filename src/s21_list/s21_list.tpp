#include <iostream>
namespace s21 {

template <typename tmp>
list<tmp>::list() : __fake{}, start{&__fake}, finish{&__fake} {
  finish->next = finish;
  finish->back = finish;
}

template <typename tmp>
list<tmp>::list(size_type n) : list<tmp>::list() {
  value_type def{};
  for (size_type i = 0; i < n; i++) {
    push_back(def);
  }
}

template <typename tmp>
list<tmp>::list(std::initializer_list<value_type> const& items)
    : list<tmp>::list() {
  for (auto it = items.begin(); it != items.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
list<tmp>::list(const list<tmp>& l) : list<tmp>::list() {
  for (const_iterator it = l.begin(); it != l.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
list<tmp>::list(list<tmp>&& l) :
__fake(l.__fake), start(l.start), finish(&__fake) {
  finish->back->next = finish;
  finish->next->back = finish;
  l.start = l.finish;
  l.finish->next = l.finish;
  l.finish->back = l.finish;
}

template <typename tmp>
list<tmp>::~list() { clear(); }

template <typename tmp>
typename s21::list<tmp>& list<tmp>::operator=(list<tmp>&& l) {
  if (this != &l) {
    clear();
    __fake = l.__fake;
    finish->back->next = finish;
    finish->next->back = finish;
    start = l.start;
    l.start = l.finish;
    l.finish->next = l.finish;
    l.finish->back = l.finish;
  }
  return *this;
}
// funcs

template <typename T>
typename s21::list<T>::ListIterator
list<T>::insert(iterator pos, const_reference value) {
  Node* tmp = new Node{pos.node, pos.node->back, value};
  tmp->back->next = tmp;
  pos.node->back = tmp;
  if (pos.node == start) start = tmp;
  pos--;
  return pos;
}

template <typename T>
typename s21::list<T>::iterator 
list<T>::erase(iterator pos) {
  Node* tmp{pos.node->next};
  pos.node->next->back = pos.node->back;
  pos.node->back->next = pos.node->next;
  if (pos.node == start) start = pos.node->next;
  delete pos.node;
  pos.node = tmp;
  return pos;
}

template <typename tmp>
void list<tmp>::push_back(const_reference val) {
  insert(end(), val);
}

template <typename T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void list<T>::pop_back() {
  erase(--end());
}

template <typename T>
void list<T>::pop_front() {
  erase(begin());
}

template <typename T>
size_t list<T>::size() {
  size_t count = 0;
  for (const_iterator it = begin(); it != end(); it++) count++;
  return count;
}

template <typename T>
void list<T>::clear() {
  while (start != finish) {
    pop_front();
  }
}

template <typename T>
void list<T>::swap(list<T>& other) {
  if (this != &other) {
      std::swap(__fake, other.__fake);
    if (!empty())
      finish->next = finish->back = finish;
    if (!other.empty())
      other.finish->next = other.finish->back = other.finish;
    finish->next->back = finish;
    finish->back->next = finish;
    start = finish->next;
    other.finish->next->back = other.finish;
    other.finish->back->next = other.finish;
    other.start = other.finish->next;
  }
}

template <typename T>
void list<T>::merge(list<T>& other) {
  if (this != &other) {
    for (iterator it = begin(); it != end() && !other.empty();
         it++) {
      while (other.front() < *it) {
        insert(it, other.front());
        other.pop_front();
      }
    }
    splice(end(), other);
  }
}

template <typename T>
void list<T>::splice(const_iterator pos, list<T>& other) {
  if (other.empty()) return;
  if (this == &other) return; //throw?
  pos.node->back->next = other.start;
  other.start->back = pos.node->back;
  other.finish->back->next = pos.node;
  pos.node->back = other.finish->back;
  other.start = other.finish;
  other.finish->back = other.finish;
  other.finish->next = other.finish;
  if (pos == begin()) start = finish->next;
}

template <typename T>
void list<T>::reverse() {
  if (!empty()) {
    Node* tmp = nullptr;
    for (iterator it = begin(); it != end(); it--) {
      tmp = it.node->next;
      it.node->next = it.node->back;
      it.node->back = tmp;
    }
    tmp = finish->next;
    finish->next = finish->back;
    finish->back = tmp;
    start = finish->next;
  }
}

template <typename T>
void list<T>::unique() {
  for (iterator iter = begin(); iter != end(); iter++) {
    iterator it(iter.node->next);
    while (*iter == *it && it != end()) it = erase(it);
  }
}

template <typename T>
void list<T>::sort() {
  value_type tmp{};
  for (iterator iter = begin(); iter != end(); iter++) {
    iterator min = iter;
    for (iterator it(iter.node->next); it != end(); it++)
      if (*min > *it) min = it;
    if (min != iter) {
      tmp = *min;
      *min = *iter;
      *iter = tmp;
    }
  }
}

template <typename T>
typename s21::list<T>::size_type
list<T>::max_size() {
  return MAX_MEMORY / sizeof(Node);
}
};  // namespace s21