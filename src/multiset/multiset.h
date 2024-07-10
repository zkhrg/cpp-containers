#ifndef CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_
#define CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_

#include "../set/set.h"

namespace s21 {

template <typename T>
class multiset : public set<T> {
 public:
  using typename set<T>::key_type;
  using typename set<T>::value_type;
  using typename set<T>::reference;
  using typename set<T>::const_reference;
  using typename set<T>::iterator;
  using typename set<T>::const_iterator;
  using typename set<T>::size_type;

 protected:
  typedef struct Node : public set<T>::Node {
    T data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    int amount;

    Node(T value, Node* n)
        : data(value),
          left(nullptr),
          right(nullptr),
          parent(n),
          height(1),
          amount(1) {}
  } Node;

  // TODO: rewrite
  Node* innerInsert(Node* n, T value, Node* p);
  Node* innerRemove(Node* m, T value);
  void innerInsert(T value);
  // Node* innerSearch(Node* node, T value) const;

 public:
  std::pair<iterator, bool> insert(const T& value);
};

}  // namespace s21
#include "template/multiset_template.hpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_
