namespace s21 {
template <typename T>
typename s21::stack<T>& stack<T>::operator=(stack<T>&& s) {
  if (this != &s) base = std::move(q.base);
}

template <typename T>
void stack<T>::push(const_reference val) {
  base.push_back(val);
}

template <typename T>
void stack<T>::pop() {
  base.pop_back();
}

template <typename T>
void stack<T>::swap(stack<T>& s) {
  if (this != &q) base.swap(s.base);
}
};  // namespace s21