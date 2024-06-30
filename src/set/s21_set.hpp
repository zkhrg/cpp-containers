#include <initializer_list>

#include "avl_tree/avl_tree.hpp"

namespace s21 {
template <class T>
class set {
 public:
  // Set Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = typename AVLTree<T>::iterator;
  using const_iterator = typename AVLTree<T>::const_iterator;
  using size_type = size_t;

  // Set Member functions
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  ~set();
  set& operator=(set&& s);

  // Set Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Set Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Set Modifiers
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  // Set Lookup
  iterator find(const T& key);
  bool contains(const T& key);

 private:
  size_type size_;
  typename AVLTree<T>::Node fake_;
  typename AVLTree<T>::Node*& top_;
  typename AVLTree<T>::Node*& min_;
  typename AVLTree<T>::Node* max_;
};

};  // namespace s21

// #include "map_iterator.tpp"
#include "s21_set.tpp"
