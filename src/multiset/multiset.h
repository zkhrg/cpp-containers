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
  std::pair<iterator, bool> insert(const value_type& value) override {
    std::cout << value << std::endl;
    return {nullptr, true};
  }
};

}  // namespace s21
#include "template/multiset_template.hpp"
#endif  // CPP2_S21_CONTAINERS_1_SRC_MULTISET_AVL_TREE_AVL_TREE_H_
