#ifndef CPP2_S21_CONTAINERS_1_SRC_
#define CPP2_S21_CONTAINERS_1_SRC_

#include "s21_vector.h"

namespace s21 {

// default constructor
template <typename T>
vector<T>::vector() noexcept : data_{nullptr}, size_{}, capacity_{} {};

// Parameterized constructor
template <typename T>
vector<T>::vector(size_type n)
    : data_{new value_type[n]}, size_{n}, capacity_{n} {
  if (n < 0) {
    throw std::range_error("Incorrect size of vector it must be >= 0");
  }
  printf("Parameterized constructor\n");
}

// Initializer list constructor
template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

// Copy constructor
template <typename T>
vector<T>::vector(const vector &v) : vector(v.size_) {
  std::copy(v.begin(), v.end(), data_);
}

// Move constructor
template <typename T>
vector<T>::vector(vector &&v) noexcept
    : data_{v.data_}, size_{v.size_}, capacity_{v.capacity_} {
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

// Destructor
template <typename T>
vector<T>::~vector() {
  delete[] data_;
  size_ = 0;
  capacity_ = 0;
  data_ = nullptr;
  printf("Destructor\n");
}

// (operator =)
template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &v) noexcept {
  if (this != &v) {
    vector copy{v};
    *this = std::move(copy);
  }
  return *this;
}

// (operator =) overload
template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&v) noexcept {
  std::swap(data_, v.data_);
  std::swap(size_, v.size_);
  std::swap(capacity_, v.capacity_);
  return *this;
}

// Methods
template <typename T>
vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return data_[pos];
}

template <typename T>
vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return data_[pos];
}

template <typename T>
vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return data_[pos];
}

template <typename T>
vector<T>::const_reference vector<T>::front() const {
  if (this->empty) {
    throw std::out_of_range("Vector is empty");
  }
  return data_[0];
}

template <typename T>
vector<T>::const_reference vector<T>::back() const {
  if (this->empty) {
    throw std::out_of_range("Vector is empty");
  }
  return data_[size_ - 1];
}

template <typename T>
vector<T>::iterator vector<T>::data() noexcept {
  return &data_[0];
}

template <typename T>
inline vector<T>::iterator vector<T>::begin() {
  return &data_[0];
}

template <typename T>
inline vector<T>::iterator vector<T>::end() {
  return &data_[size_];
}

template <typename T>
inline vector<T>::const_iterator vector<T>::cbegin() const {
  return &data_[0];
}

template <typename T>
inline vector<T>::const_iterator vector<T>::cend() const {
  return &data_[size_];
}

template <typename T>
inline bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
inline vector<T>::size_type vector<T>::size() const {
  return size_;
}

// чё за нах?
template <typename T>
inline vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<size_t>::max() / sizeof(int) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size <= capacity_)
    return;
  else if (size > max_size()) {
    throw std::length_error("Size is larger than maximum of capacity")
  }
  iterator new_data = new value_type[size];
  std::copy(begin(), end(), new_data);
  delete[] data_;
  capacity_ = size;
  data_ = new_data;
}

template <typename T>
vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    iterator new_data = new value_type[size_];
    std::copy(begin(), end(), new_data);
    delete[] data_;
    capacity_ = size_;
    data_ = new_data;
  }
}

// vector modifier
template <typename T>
void vector<T>::clear() noexcept {
  for (size_t i = 0; i < size(); i++) {
    data_[i] = 0;
  }
  size_ = 0;
}

template <typename T>
vector<T>::iterator vector<T>::insert(iterator pos, const_reference value) {
  if (pos < begin() || pos > end()) return;
  if (size_ == capacity_) reserve(capacity_ ? capacity_ * 2 : 1);

  size_type pos_num = pos - begin();
  push_back(value);
  std::rotate(begin() + pos, end() - 1, end());

  iterator new_pos = begin() + pos_num;
  size_++;

  return new_pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  if (pos < begin() || pos > end()) return;
  std::move(begin() + pos + 1, end(), begin() + pos);
  pop_back();
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) reserve(capacity_ ? capacity_ * 2 : 1);
  data_[size_++] = value;
}

template <typename T>
void vector<T>::pop_back() {
  size_ > 0 ? size_-- : 0;
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_