#ifndef SAMPLE_TEST
#define SAMPLE_TEST

template <typename T>
T max(T a, T b);

template <class T>
class SNode {
 private:
  T arg;

 public:
  SNode<T> *next, *back;

  using arg_type = T;
  using refrence = T &;
  using const_refrence = const T &;

  SNode(arg_type val) : arg(val), next(nullptr), back(nullptr){};
  ~SNode();
};
#include "sample.tpp"

#endif