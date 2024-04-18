#ifndef S21_UTILS
#define S21_UTILS

namespace s21_utils {
template <typename tmp>
struct Node {
  Node<tmp>*next, *back;
  tmp arg;
};

template <typename T>
class ListConstIterator;

template <typename T>
class ListIterator {
  friend class ListConstIterator<T>;

 private:
  Node<T>* node;

 public:
  ListIterator(Node<T>*& other) : node(other){};
  ~ListIterator(){};

  T& operator*() { return node->arg; }
  ListIterator& operator++();
  ListIterator& operator--();
  ListIterator operator++(int);
  ListIterator operator--(int);
  bool operator!=(ListIterator<T> it) { return node != it.node; };
  bool operator!=(ListConstIterator<T> it) { return node != it.node; };
  bool operator==(ListIterator<T> it) { return node == it.node; };
  bool operator==(ListConstIterator<T> it) { return node == it.node; };
};

template <typename T>
class ListConstIterator {
  friend class ListIterator<T>;

 private:
  const Node<T>* node;

 public:
  ListConstIterator(Node<T>* const other) : node(other){};
  ListConstIterator(ListIterator<T>& other) : node(other.node){};
  ListConstIterator(ListIterator<T>&& other) : node(other.node) {
    other.node = nullptr;
  };
  ~ListConstIterator(){};

  const T& operator*() { return node->arg; }
  bool operator!=(ListConstIterator<T> it) { return node != it.node; };
  bool operator!=(ListIterator<T> it) { return node != it.node; };
  bool operator==(ListIterator<T> it) { return node == it.node; };
  bool operator==(ListConstIterator<T> it) { return node == it.node; };
  ListConstIterator& operator++();
  ListConstIterator& operator--();
  ListConstIterator operator++(int);
  ListConstIterator operator--(int);
  ListConstIterator& operator=(ListIterator<T>& it);
};

};  // namespace s21_utils

#include "utils.tpp"

#endif