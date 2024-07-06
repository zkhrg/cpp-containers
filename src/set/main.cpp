#include <iostream>
#include <set>

#include "avl_tree/avl_tree.hpp"
// #include "s21_set.hpp"

int main() {
  s21::set<int> s1;
  s1.insert(3);
  s1.insert(4);
  s1.insert(5);
  s1.insert(6);
  // std::cout << s1.root->data << std::endl;
  // s21::set<int> s{3, 4, 5, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  4,
  //                 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  4,
  //                 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 192};
  // s21::set<int> s1(std::move(s));
  // // s21::set<int> s1(s);

  // int searchValue = 192;
  // // std::cout << s.root->left->data << std::endl;
  // s21::set<int>::Node* result = s1.search(searchValue);
  // if (result != nullptr) {
  //   std::cout << "found v: " << result->parent->data << std::endl;
  // } else {
  //   std::cout << "nf(((" << std::endl;
  // }
  // std::cout << (s.root == nullptr) << std::endl;

  s21::set<int> mySet{7, 3, -1, 4, 876, 5123, 7, 9, 0, 222, 011, 14,
                      7, 7, 7,  7, 7,   7,    7, 7, 7, 7,   7,   7,
                      7, 7, 7,  7, 7,   7,    7, 7, 7, 7,   7};
  std::cout << "Elements in the set:" << std::endl;
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  int v = -1;
  std::cout << "udalen" << v << std::endl;
  mySet.erase(mySet.begin());
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << " ";
  }

  std::cout << "size is: " << mySet.size() << std::endl;
  std::cout << "max_size my is:   " << mySet.max_size() << std::endl;
  s21::set<int> setik{5, 5, 5, 5, 6, 4, 36, 37, -1202};
  std::cout << "max_size orig is: " << setik.max_size() << std::endl;
  auto it = mySet.insert(7).first;
  it--;
  std::cout << "is added 876?" << *it << std::endl;
  // std::cout << "value after insert 876: " << (*(--(it))) << std::endl;
  // s1.swap(setik);
  // s1.merge(setik);
  for (auto it = s1.begin(); it != s1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << setik.contains(4) << std::endl;
  std::cout << *(setik.find(4)) << std::endl;
  return 0;
}
