namespace s21 {

// ListIterator==========================================================

template <typename tmp>
typename s21::list<tmp>::ListIterator& list<tmp>::ListIterator::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21::list<tmp>::ListIterator& list<tmp>::ListIterator::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21::list<tmp>::ListIterator list<tmp>::ListIterator::operator++(int) {
  iterator out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21::list<tmp>::ListIterator list<tmp>::ListIterator::operator--(int) {
  iterator out(*this);
  this->node = this->node->back;
  return out;
}

// ListConstItarator===================================================

template <typename tmp>
typename s21::list<tmp>::ListConstIterator&
list<tmp>::ListConstIterator::operator++() {
  this->node = this->node->next;
  return *this;
}

template <typename tmp>
typename s21::list<tmp>::ListConstIterator&
list<tmp>::ListConstIterator::operator--() {
  this->node = this->node->back;
  return *this;
}

template <typename tmp>
typename s21::list<tmp>::ListConstIterator
list<tmp>::ListConstIterator::operator++(int) {
  const_iterator out(*this);
  this->node = this->node->next;
  return out;
}

template <typename tmp>
typename s21::list<tmp>::ListConstIterator
list<tmp>::ListConstIterator::operator--(int) {
  const_iterator out(*this);
  this->node = this->node->back;
  return out;
}

template <typename T>
typename s21::list<T>::ListConstIterator& list<T>::ListConstIterator::operator=(
    const iterator& it) {
  node = it.node;
  return *this;
}

};  // namespace s21