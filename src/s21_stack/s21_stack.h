#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_STACK_S21_STACK_H_

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
  stack(const stack &s) : base(s.base){};
  stack(stack &&s) : base(std::move(s.base)){};
  ~stack(){};
  stack &operator=(stack &&s);
  stack &operator=(const stack &s);
  // Queue Element access:
  const_reference top() { return base.back(); };
  // Queue Capacity:
  bool empty() { return base.empty(); };
  size_type size() { return base.size(); };
  // Queue Modifiers:
  void push(const_reference value);
  void pop();
  void swap(stack &other);

  template <typename... Args>
  void insert_many_front(Args &&...args);
};
};  // namespace s21

#include "s21_stack.tpp"

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_STACK_S21_STACK_H_
