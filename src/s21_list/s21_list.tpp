namespace s21 {

template <typename tmp>
s21_list<tmp>::s21_list() {
  Node* fake = new Node{};
  start = finish = fake;
}

template <typename tmp>
s21_list<tmp>::s21_list(size_type n) : s21_list<tmp>::s21_list() {
  value_type def{};
  for (size_type i = 0; i < n; i++) {
    push_back(def);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(std::initializer_list<value_type> const& items)
    : s21_list<tmp>::s21_list() {
  for (auto it = items.begin(); it != items.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(const s21_list<tmp>& list) : s21_list<tmp>::s21_list() {
  for (const_iterator it = list.begin(); it != list.end(); it++) {
    push_back(*it);
  }
}

template <typename tmp>
s21_list<tmp>::s21_list(s21_list<tmp>&& list)
    : start(list.start), finish(list.finish) {
  list.start = nullptr;
  list.finish = nullptr;
}

template <typename tmp>
s21_list<tmp>::~s21_list() {
  clear();
  if(finish) delete finish;
}

template <typename tmp>
typename s21::s21_list<tmp>& s21_list<tmp>::operator=(s21_list<tmp>&& list) {
  if(this != &list){
    clear();
    if(finish) delete finish;
    start = list.start;
    finish = list.finish;
    list.start = nullptr;
    list.finish = nullptr;
  }
  return *this;
}
// funcs

template <typename T>
typename s21::s21_list<T>::ListIterator
s21_list<T>::insert(iterator pos, const_reference value){
  Node* tmp = new Node{pos.node, pos.node->back, value};
  if (tmp->back)
    tmp->back->next = tmp;
  pos.node->back = tmp;
  if (pos.node == start)
    start = tmp;
  pos--;
  return pos;
}

template <typename T>
void s21_list<T>::erase(iterator pos) {
  if(pos != end()){
    pos.node->next->back = pos.node->back;
    if (pos.node->back)
      pos.node->back->next = pos.node->next;
    else
      start = pos.node->next;
    delete pos.node;
  }
}

template <typename tmp>
void s21_list<tmp>::push_back(const_reference val) {
  insert(end(), val);
}

template <typename T>
void s21_list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void s21_list<T>::pop_back(){
  if(start != finish) erase(--end());
}

template <typename T>
void s21_list<T>::pop_front(){
  erase(begin());
}

template <typename T>
size_t s21_list<T>::size() {
  size_t count = 0;
  for (const_iterator it = begin(); it != end(); it++) count++;
  return count;
}

template <typename T>
void s21_list<T>::clear(){
  while (start != finish) {
    pop_front();
  }
}

template <typename T>
void s21_list<T>::swap(s21_list<T>& other) {
  Node* buf = start;
  start = other.start;
  other.start = buf;
  buf = finish;
  finish = other.finish;
  other.finish = buf;
}


template <typename T>
void s21_list<T>::merge(s21_list<T>& other) {
  if (this != &other) {
    for(iterator it = begin(); it != end() && other.start != other.finish; it++) {
      if(other.front() < *it) {
        insert(it, other.front());
        other.pop_front();
      }
    }
    splice(end(), other);
  }
}


template <typename T>
void s21_list<T>::splice(const_iterator pos, s21_list<T>& other) {
  pos.node->back->next = other.start;
  other.start->back = pos.node->back;
  other.finish->back->next = pos.node;
  pos.node->back = other.finish->back;
  other.start = other.finish;
  other.finish->back = nullptr;
}


template <typename T>
void s21_list<T>::reverse() {
  if (start != finish){
    Node* tmp = nullptr;
    for(iterator it = begin(); it != end(); it--) {
      tmp = it.node->next;
      it.node->next = it.node->back;
      it.node->back = tmp;
    }
    tmp = start;
    start = finish->back;
    start->back = nullptr;
    finish->back = tmp;
    tmp->next = finish;
  }
}

template <typename T>
void s21_list<T>::unique() {
  for (iterator iter = begin(); iter != end(); iter++)
    for (iterator it(iter.node->next); it != end(); it++)
      if(*iter == *it) erase(it);
}

template <typename T>
void s21_list<T>::sort() {
  value_type tmp{};
  for (iterator iter = begin(); iter != end(); iter++) {
    iterator min = iter;
    for (iterator it(iter.node->next); it != end(); it++)
      if(*min > *it) min = it;
    if (min != iter){
      tmp = *min;
      *min = *iter;
      *iter = tmp;
    }
  }
}
};  // namespace s21