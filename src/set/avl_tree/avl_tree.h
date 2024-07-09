#ifndef CPP2_S21_CONTAINERS_1_SRC_SET_AVL_TREE_AVL_TREE_H_
#define CPP2_S21_CONTAINERS_1_SRC_SET_AVL_TREE_AVL_TREE_H_

#include <initializer_list>
#include <iostream>

#define MAX_MEMORY ((~(size_t)0) >> 1)

namespace s21 {
template <typename T>
class set {
 public:
  class SetConstIterator;
  class SetIterator;

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
    Node* parent;
    int height;

    Node(T value, Node* n)
        : data(value), left(nullptr), right(nullptr), parent(n), height(1) {}
  } Node;

  template <class Iter>
  class BaseIterator {
   public:
    Node* node;

   public:
    BaseIterator() : node(nullptr){};
    ~BaseIterator(){};

    Iter* operator++();
    Iter* operator--();
    Iter operator++(int);
    Iter operator--(int);
    bool operator==(iterator it) const { return node == it.node; };
    bool operator==(const_iterator it) const { return node == it.node; };
    bool operator!=(iterator it) const { return node != it.node; };
    bool operator!=(const_iterator it) const { return node != it.node; };

   public:
    Node* findNext(Node* z);
    Node* findPrev(Node* z);
  };

 public:
  class SetIterator : public BaseIterator<SetIterator> {
    friend class BaseIterator<SetIterator>;
    friend class BaseIterator<SetConstIterator>;
    friend class set;

   public:
    SetIterator(Node* other = nullptr) { this->node = other; };
    ~SetIterator(){};

    reference operator*();
    value_type* operator->();
  };

  class SetConstIterator : public BaseIterator<SetConstIterator> {
    friend class BaseIterator<SetIterator>;
    friend class BaseIterator<SetConstIterator>;
    friend class set;

   public:
    SetConstIterator(Node* const other = nullptr) { this->node = other; };
    SetConstIterator(const SetIterator& other) { this->node = other.node; };
    SetConstIterator(SetIterator&& other) {
      this->node = other.node;
      other.node = nullptr;
    };
    ~SetConstIterator(){};

    const_iterator& operator=(const iterator& it) const;
    const_reference operator*() const;
    const value_type* operator->() const;
  };

 public:
  //  private:
  Node* root;

 private:
  int height(Node* n) const;
  int balanceFactor(Node* n) const;
  void updateHeight(Node* n);
  size_type len;
  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);

  Node* innerInsert(Node* n, T value, Node* p);
  Node* innerRemove(Node* m, T value);
  Node* minValueNode(Node* node);
  Node* innerSearch(Node* n, T value) const;
  void innerInsert(T value);
  void clear(Node*& n);

 public:
  size_type size();
  size_type max_size();
  std::pair<typename set<T>::iterator, bool> insert(const value_type& value);

  void clear();
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  iterator find(const_reference key) const;
  bool contains(const_reference value) const;

  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  ~set();
  set& operator=(const set& s);
  set& operator=(set&& s);

  bool empty() const;

  iterator begin();
  iterator end() { return iterator(nullptr); };
  const_iterator begin() const;
  const_iterator end() const { return const_iterator(); }
};
}  // namespace s21

#include "avl_tree.tpp"
#include "iter.tpp"

#endif  // CPP2_S21_CONTAINERS_1_SRC_SET_AVL_TREE_AVL_TREE_H_