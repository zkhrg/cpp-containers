#pragma once  // rewrite

#include <iostream>

namespace s21 {
template <typename T>
class AVLTree {
 public:
  class ConstIterator;
  class Iterator;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const reference;

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
    bool operator==(iterator it);
    bool operator==(const_iterator it);
    bool operator!=(iterator it);
    bool operator!=(const_iterator it);

   protected:
    bool goLeft();
    bool goRight();
    bool goParent();
  };

 public:
  class Iterator : public BaseIterator<Iterator> {
    friend class map;
    friend class BaseIterator<Iterator>;
    friend class BaseIterator<ConstIterator>;

   public:
    Iterator(Node* nd) { this->node = nd; };
    ~Iterator(){};

    reference operator*();
    value_type* operator->();
  };

  class ConstIterator : public BaseIterator<ConstIterator> {
    friend class map;
    friend class BaseIterator<Iterator>;
    friend class BaseIterator<ConstIterator>;

   public:
    ConstIterator(Node* const nd) { this->node = nd; };
    ConstIterator(const iterator& it) { this->node = it.node; };
    ConstIterator(iterator&& it) {
      this->node = it.node;
      it.node = nullptr;
    };
    ~ConstIterator(){};

    const_iterator& operator=(const iterator& it) const;
    const_reference operator*() const;
    const value_type* operator->() const;
  };

 private:
  Node* root;

  int height(Node* n) const;
  int balanceFactor(Node* n) const;
  void updateHeight(Node* n);

  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);

  Node* insert(Node* n, T value);
  Node* search(Node* n, T value) const;
  void clear(Node* n);

 public:
  AVLTree();
  ~AVLTree();

  void insert(T value);
  Node* search(T value) const;
};
}  // namespace s21

#include "avl_tree.tpp"
