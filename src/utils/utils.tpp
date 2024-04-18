namespace s21_utils {

// ListIterator==========================================================

template <typename tmp>
typename s21_utils::ListIterator<tmp>& ListIterator<tmp>::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21_utils::ListIterator<tmp>& ListIterator<tmp>::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21_utils::ListIterator<tmp> ListIterator<tmp>::operator++(int) {
  ListIterator<tmp> out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21_utils::ListIterator<tmp> ListIterator<tmp>::operator--(int) {
  ListIterator<tmp> out(*this);
  this->node = this->node->back;
  return out;
}

// ListConstItarator===================================================

template <typename tmp>
typename s21_utils::ListConstIterator<tmp>&
ListConstIterator<tmp>::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21_utils::ListConstIterator<tmp>&
ListConstIterator<tmp>::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21_utils::ListConstIterator<tmp> ListConstIterator<tmp>::operator++(
    int) {
  ListConstIterator<tmp> out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21_utils::ListConstIterator<tmp> ListConstIterator<tmp>::operator--(
    int) {
  ListConstIterator<tmp> out(*this);
  this->node = this->node->back;
  return out;
}

template <typename T>
typename s21_utils::ListConstIterator<T>& ListConstIterator<T>::operator=(
    ListIterator<T>& it) {
  node = it.node;
  return *this;
}

};  // namespace s21_utils