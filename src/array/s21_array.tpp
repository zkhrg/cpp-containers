#ifndef CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_ARRAY_TPP_
#include "s21_array.h"

namespace s21 {

// default constructor
template <typename T, std::size_t N>
array<T, N>::array() noexcept : size_(N) {}

// Initializer list constructor
template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), data_);
}

// Copy constructor
template <typename T, std::size_t N>
array<T, N>::array(const array<T, N> &a) {
  std::copy(a.data_, a.data_ + N, data_);
}

// Move constructor
template <typename T, std::size_t N>
array<T, N>::array(array<T, N> &&a) noexcept {
  std::move(a.data_, a.data_ + N, data_);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_ARRAY_TPP_