#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector() noexcept;
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();
  vector &operator=(const vector &v);
  vector &operator=(vector &&v) noexcept;

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;  // ???????????? делаем?
  const_reference front() const;
  const_reference back() const;
  iterator data() noexcept;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;  // ??????????? делаем?
  const_iterator cend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

 private:
  iterator data_;
  size_type size_;
  size_type capacity_;
};

#include "vector.tpp"
}  // namespace s21
