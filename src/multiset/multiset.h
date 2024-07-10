#ifndef CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_
#define CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_

#include <initializer_list>

#include "../set/set.h"

namespace s21 {

template <typename T>
class multiset : public set<T> {
 public:
  // class SetConstIterator;
  // class SetIterator;
  using typename set<T>::key_type;
  using typename set<T>::value_type;
  using typename set<T>::reference;
  using typename set<T>::const_reference;
  using typename set<T>::iterator;
  using typename set<T>::const_iterator;
  using typename set<T>::size_type;
  using set<T>::set;

 public:
  std::pair<iterator, bool> insert(const T& value);

  void erase(iterator pos);

  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& s);
  multiset(multiset&& s);
  multiset<T>& operator=(const multiset& s);
  multiset<T>& operator=(multiset&& s);

  void merge(multiset& other);

  size_type count(T value) {
    return this->innerSearch(this->root, value)->amount;
  };

  // TODO: rewrite
  typename set<T>::Node* innerInsert(typename set<T>::Node* node, T value,
                                     typename set<T>::Node* parent);
  void innerInsert(T value);
};

}  // namespace s21
#include "template/multiset_iterator_template.hpp"
#include "template/multiset_template.hpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_
