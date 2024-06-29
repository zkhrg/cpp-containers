#include <initializer_list>

namespace s21 {
template <class T>
class set {
 public:
  class SetIterator;       // NEED
  class SetConstIterator;  // NEED

  using value_type = T;                     // NEED
  using reference = T&;                     // NEED
  using const_reference = const T&;         // NEED
  using iterator = SetIterator;             // NEED
  using const_iterator = SetConstIterator;  // NEED
  using size_type = size_t;                 // NEED

  set();                                                // NEED
  set(std::initializer_list<value_type> const& items);  // NEED
  set(const set& s);                                    // NEED
  set(set&& s);                                         // NEED
  ~set();                                               // NEED
  operator=(set && s);                                  // NEED

  iterator begin();  // NEED
  iterator end();    // NEED

  bool empty();          // NEED
  size_type size();      // NEED
  size_type max_size();  // NEED

  void clear();                                               // NEED
  std::pair<iterator, bool> insert(const value_type& value);  // NEED
  void erase(iterator pos);                                   // NEED
  void swap(set& other);                                      // NEED
  void merge(set& other);                                     // NEED

  iterator find(const Key& key);  // NEED
  bool contains(const Key& key);  // NEED
};

}  // namespace s21
