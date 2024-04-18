namespace s21 {
template <typename tmp>
s21_list<tmp>::s21_list() {
  Node<value_type>* fake = new Node<value_type>{};
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
  for (; start != finish; start = start->next) {
    delete start->back;
  }
  delete finish;
}
// funcs

template <typename tmp>
void s21_list<tmp>::push_back(const_reference val) {
  Node<value_type>* ptr = finish->back;
  Node<value_type>* nd = new Node<value_type>;
  nd->arg = val;
  if (ptr) {
    ptr->next = nd;
    nd->back = ptr;
  } else {
    start = nd;
  }
  nd->next = finish;
  finish->back = nd;
}

};  // namespace s21