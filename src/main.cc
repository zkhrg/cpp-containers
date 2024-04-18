#include <iostream>

#include "s21_containers.h"

using namespace std;
using namespace s21;

int main() {
  s21_list<int> a{1, 2, 3, 4, 5};
  s21_list b(a);

  for (auto iter = b.begin(); iter != b.end(); ++iter) {
    cout << *iter << endl;
  }
  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    *iter = 0;
    cout << *iter << endl;
  }

  return 0;
}