#ifndef S21_STACK
#define S21_STACK

#include "../s21_list/s21_list.h"

namespace s21 {
template <class T>
class stack {
 private:
  list<T> base;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // member func:
  stack() : base(){};
  stack(std::initializer_list<value_type> const &items) : base(items){};
  stack(const stack &s) const : base(s.base){};
  stack(stack &&s) : base(std::move(s.base)){};
  ~stack(){};
  stack &operator=(stack &&s);
  // Queue Element access:
  const_reference top() { return base.back(); };
  // Queue Capacity:
  bool empty() { return base.empty(); };
  size_type size() { return base.size(); };
  // Queue Modifiers:
  void push(const_reference value);
  void pop();
  void swap(stack &other);
};
};  // namespace s21

#include "s21_stack.tpp"

#endif