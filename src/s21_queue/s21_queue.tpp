namespace s21 {
template <typename T>
typename s21::queue<T>& queue<T>::operator=(queue<T>&& q) {
  if (this != &q) base = std::move(q.base);
}

template <typename T>
void queue<T>::push(const_reference val) {
  base.push_back(val);
}

template <typename T>
void queue<T>::pop() {
  base.pop_front();
}

template <typename T>
void queue<T>::swap(queue<T>& q) {
  if (this != &q) base.swap(q.base);
}
};  // namespace s21