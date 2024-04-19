namespace s21 {

// ListIterator==========================================================

template <typename tmp>
typename s21::s21_list<tmp>::ListIterator&
s21_list<tmp>::ListIterator::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListIterator&
s21_list<tmp>::ListIterator::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListIterator
s21_list<tmp>::ListIterator::operator++(int) {
  iterator out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListIterator
s21_list<tmp>::ListIterator::operator--(int) {
  iterator out(*this);
  this->node = this->node->back;
  return out;
}

// ListConstItarator===================================================

template <typename tmp>
typename s21::s21_list<tmp>::ListConstIterator&
s21_list<tmp>::ListConstIterator::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListConstIterator&
s21_list<tmp>::ListConstIterator::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListConstIterator
s21_list<tmp>::ListConstIterator::operator++(int) {
  const_iterator out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21::s21_list<tmp>::ListConstIterator
s21_list<tmp>::ListConstIterator::operator--(int) {
  const_iterator out(*this);
  this->node = this->node->back;
  return out;
}

template <typename T>
typename s21::s21_list<T>::ListConstIterator&
s21_list<T>::ListConstIterator::operator=(iterator& it) {
  node = it.node;
  return *this;
}

};  // namespace s21