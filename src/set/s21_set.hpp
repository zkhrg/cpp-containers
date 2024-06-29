#include <initializer_list>

namespace s21 {
template <class T>
class set {
 public:
  // Set Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = SetIterator;             // в avltree нужно
  using const_iterator = SetConstIterator;  // в avltree нужно
  using size_type = size_t;

  // Set Member functions
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  ~set();
  operator=(set && s);

  // Set Iterators
  iterator begin();
  iterator end();
  const_iterator begin();
  const_iterator end();

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
  iterator find(const Key& key);
  bool contains(const Key& key);
};

}  // namespace s21
