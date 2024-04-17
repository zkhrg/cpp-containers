#include <iostream>

#include "s21_containers.h"

using namespace std;
using namespace s21;

int main() {
  s21_list<int> a{1, 2, 3, 4, 5};

  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    cout << *iter << endl;
  }

  return 0;
}