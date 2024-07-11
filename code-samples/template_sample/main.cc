#include <iostream>

#include "sample.h"

using std::cout;

int main() {
  cout << "Testing template function\n\n";
  cout << max<int>(1, 2) << std::endl;
  cout << max(1.8, 5.6) << std::endl;
  cout << max<int>(6.5, 5.7) << std::endl;

  cout << "Testing template class\n\n";
  SNode<int> *n = new SNode<int>(0);
  n->next = new SNode<int>(1);
  n->back = new SNode<int>(2);

  delete n;
  return 0;
}