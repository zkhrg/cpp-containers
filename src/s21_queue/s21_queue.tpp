<<<<<<< HEAD
namespace s21 {
template <typename T>
typename s21::queue<T>& queue<T>::operator=(queue<T>&& q) {
  if (this != &q) base = std::move(q.base);
}

=======
#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_S21_QUEUE_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_S21_QUEUE_TPP_

namespace s21 {
template <typename T>
queue<T>& queue<T>::operator=(queue<T>&& q) {
  if (this != &q) {
    base = std::move(q.base);
  }
  return *this;
}

// template <typename T>
// queue<T>& queue<T>::operator=(const queue<T>& q) {
//   if (this != &q) {
//     base = q.base;
//   }
//   return *this;
// }

>>>>>>> origin/kalynkei
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
<<<<<<< HEAD
}
};  // namespace s21
=======
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_S21_QUEUE_TPP_
>>>>>>> origin/kalynkei
