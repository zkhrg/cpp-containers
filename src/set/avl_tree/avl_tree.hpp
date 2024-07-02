#pragma once  // rewrite

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class set {
 public:
  class SetIterator;
  class SetConstIterator;

  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = SetIterator;
  using const_iterator = SetConstIterator;
  using size_type = size_t;

 public:
  typedef struct Node {
    T data;
    Node* left;
    Node* right;
    int height;

    Node(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
  } Node;

  template <class Iter>
  class BaseIterator {
   protected:
    Node* node;

   public:
    BaseIterator() : node(nullptr){};
    ~BaseIterator(){};

    Iter operator++();
    Iter operator--();
    Iter operator++(int);
    Iter operator--(int);
    bool operator!=(SetIterator it) const { return node != it.node; };
    bool operator!=(SetConstIterator it) const { return node != it.node; };
    bool operator==(SetIterator it) const { return node == it.node; };
    bool operator==(SetConstIterator it) const { return node == it.node; };
  };

 public:
  class SetIterator : public BaseIterator<SetIterator> {
    friend class BaseIterator<SetIterator>;
    friend class BaseIterator<SetConstIterator>;
    friend class set;

   public:
    SetIterator(Node* other = nullptr) { this->node = other; };
    ~SetIterator(){};

    T& operator*() { return this->node->arg; }
  };

  class SetConstIterator : public BaseIterator<SetConstIterator> {
    friend class BaseIterator<SetIterator>;
    friend class BaseIterator<SetConstIterator>;
    friend class list;

   public:
    SetConstIterator(Node* const other = nullptr) { this->node = other; };
    SetConstIterator(const SetIterator& other) { this->node = other.node; };
    SetConstIterator(SetIterator&& other) {
      this->node = other.node;
      other.node = nullptr;
    };
    ~SetConstIterator(){};

    const T& operator*() { return this->node->arg; }
  };

 public:
  //  private:
  Node* root;

 private:
  int height(Node* n) const;
  int balanceFactor(Node* n) const;
  void updateHeight(Node* n);

  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);

  Node* insert(Node* n, T value);
  Node* search(Node* n, T value) const;
  void clear(Node* n);

 public:
  set();
  set(std::initializer_list<value_type> const& items);
  // set(const set& s);
  set(set&& s);
  ~set();
  set& operator=(set&& s);

  void insert(T value);
  bool isEmpty() const;
  Node* search(T value) const;
};
}  // namespace s21

#include "avl_tree.tpp"
