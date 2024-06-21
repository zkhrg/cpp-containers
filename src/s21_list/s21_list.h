#ifndef S21_LIST
#define S21_LIST

#include <initializer_list>


#define MAX_MEMORY ((~(size_t)0) >> 1)

namespace s21 {

template <class T>
class list {
 private:
  struct Node {
    Node *next, *back;
    T arg;
  };

 public:
  class ListConstIterator;

  class ListIterator {
    friend class ListConstIterator;
    friend class list;

   private:
    Node* node;

   public:
    ListIterator(Node*& other) : node(other){};
    ~ListIterator(){};

    T& operator*() { return node->arg; }
    ListIterator& operator++();
    ListIterator& operator--();
    ListIterator operator++(int);
    ListIterator operator--(int);
    bool operator!=(ListIterator it) const { return node != it.node; };
    bool operator!=(ListConstIterator it) const { return node != it.node; };
    bool operator==(ListIterator it) const { return node == it.node; };
    bool operator==(ListConstIterator it) const { return node == it.node; };
  };

  class ListConstIterator {
    friend class ListIterator;
    friend class list;

   private:
    Node* node;

   public:
    ListConstIterator(Node* const other) : node(other){};
    ListConstIterator(const ListIterator& other) : node(other.node){};
    ListConstIterator(ListIterator&& other) : node(other.node) {
      other.node = nullptr;
    };
    ~ListConstIterator(){};

    const T& operator*() { return node->arg; }
    bool operator!=(ListConstIterator it) const { return node != it.node; };
    bool operator!=(ListIterator it) const { return node != it.node; };
    bool operator==(ListIterator it) const { return node == it.node; };
    bool operator==(ListConstIterator it) const { return node == it.node; };
    ListConstIterator& operator++();
    ListConstIterator& operator--();
    ListConstIterator operator++(int);
    ListConstIterator operator--(int);
    ListConstIterator& operator=(const ListIterator& it);
  };

 private:
  Node __fake;
  Node* start;
  Node* finish;

 public:
  // List Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  // List Functions
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();

  list& operator=(list&& l);

  // List Element access
  const_reference front() { return start->arg; }
  const_reference back() { return finish->back->arg; }

  // List Iterators
  iterator begin() { return iterator(start); };
  iterator end() { return iterator(finish); };
  const_iterator begin() const { return const_iterator(start); }
  const_iterator end() const { return const_iterator(finish); }

  // List Capacity
  bool empty() { return start == finish; };
  size_type size();
  size_type max_size();


  // List Modifiers
  iterator insert(iterator pos, const_reference value);
  iterator erase(iterator pos);
  void push_back(const_reference val);
  void push_front(const_reference value);
  void pop_back();
  void pop_front();
  void clear();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
};

};  // namespace s21
#include "internal_class.tpp"
#include "s21_list.tpp"

#endif