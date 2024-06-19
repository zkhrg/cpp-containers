#include "../test.h"
#include <list>
#include <iostream>

// List Functions

TEST(ListTests, TestDefaultListConstructor) {
  s21::list<int> l1;
  std::list<int> l2;
  EXPECT_EQ(l1.size(), l2.size());
  EXPECT_EQ(l1.empty(), true);
  EXPECT_EQ(l2.empty(), true);
}

TEST(ListTests, TestSizeListConstructor) {
  s21::list<int> l1(45);
  std::list<int> l2(45);
  EXPECT_EQ(l1.size(), l2.size());
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for(; it1 != l1.end() && it2 != l2.end(); it1++, it2++)
    EXPECT_EQ(*it1, *it2);
}

TEST(ListTests, Test_IntitList_ListConstructor) {
  s21::list<double> l1{2.5, 3.5, 4.5};
  std::list<double> l2{2.5, 3.5, 4.5};
  EXPECT_EQ(l1.size(), l2.size());
  EXPECT_EQ(l1.empty(), false);
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for(; it1 != l1.end() && it2 != l2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(ListTests, TestCopyListConstructor) {
  s21::list<double> l1{2.5, 3.5, 4.5};
  s21::list<double> l2(l1);
  EXPECT_EQ(l1.size(), l2.size());
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for(; it1 != l1.end() && it2 != l2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(ListTests, TestMoveListConstructor) {
  s21::list<double> l1{2.5, 3.5, 4.5};
  s21::list<double> l2(l1);
  s21::list<double> l3(std::move(l1));
  EXPECT_EQ(l3.size(), l2.size());
  EXPECT_EQ(l1.empty(), true);
  auto it1 = l3.begin();
  auto it2 = l2.begin();
  for(; it1 != l3.end() && it2 != l2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(ListTests, TestOPMoveListConstructor) {
  s21::list<double> l1{2.5, 3.5, 4.5};
  s21::list<double> l2(l1);
  s21::list<double> l3{1, 5, 3, 7, 5};
  l3 = std::move(l1);
  EXPECT_EQ(l3.size(), l2.size());
  EXPECT_EQ(l1.empty(), true);
  auto it1 = l3.begin();
  auto it2 = l2.begin();
  for(; it1 != l3.end() && it2 != l2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

// List Element access

TEST(ListTests, TestFrontListAccess1){
  s21::list<int> l1;
  std::list<int> l2;
  EXPECT_EQ(l1.front(), l2.front());
  l1 = s21::list<int>{1, 2, 3};
  l2 = std::list<int>{1, 2, 3};
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.front(), *l1.begin());
}

TEST(ListTests, TestBackListAccess2){
  s21::list<int> l1;
  std::list<int> l2;
  EXPECT_EQ(l1.back(), l2.back());
  l1 = s21::list<int>{1, 2, 3};
  l2 = std::list<int>{1, 2, 3};
  EXPECT_EQ(l1.back(), l2.back());
  EXPECT_EQ(l1.back(), *--l1.end());
}

// List Iterators

TEST(ListTests, S21_TestConstListIterator) {
  s21::list<int> l{1, 5, 3, 7};
  s21::list<int>::iterator it = l.begin();
  s21::list<int>::const_iterator cit = l.begin();
  for(; it != l.end() && cit != l.end(); it++, cit++) {
    EXPECT_EQ(it, cit);
    EXPECT_EQ(*it, *cit);
  }
}
/*  //check std
TEST(ListTests, STD_TestConstListIterator) {
  std::list<int> l{1, 5, 3, 7};
  std::list<int>::iterator it = l.begin();
  std::list<int>::const_iterator cit = l.begin();
  for(; it != l.end() && cit != l.end(); it++, cit++) {
    EXPECT_EQ(it, cit);
    EXPECT_EQ(*it, *cit);
  }
}
*/
// List Modifiers

TEST(ListTests, TestListInsert){
  s21::list<int> l1;
  std::list<int> l2;
  l1.insert(l1.begin(), 1);
  l2.insert(l2.begin(), 1);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), 1);
  EXPECT_EQ(l2.back(), 1);
  l1.insert(l1.end(), 5);
  l2.insert(l2.end(), 5);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.back(), 5);
  EXPECT_EQ(l2.back(), 5);
}
/* //check std
TEST(ListTests, STD_TestListErase){
  std::list<int> l{1, 2, 3, 4, 5, 6};
  for(auto it = l.begin(); it != l.end(); it++) {
    if(*it % 2) it = l.erase(it);
  }
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(l.front(), 2);
  EXPECT_EQ(l.back(), 6);
}
*/

TEST(ListTests, S21_TestListErase){
  s21::list<int> l{1, 2, 3, 4, 5, 6};
  for(auto it = l.begin(); it != l.end(); it++) {
    while(*it % 2) it = l.erase(it);
  }
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(l.front(), 2);
  EXPECT_EQ(l.back(), 6);
}

/* //fake node is not allocate
TEST(ListTests, EXPECT_THROW_TestListErase){
  std::list<int> l{1, 2, 3, 4, 5, 6};
  EXPECT_ANY_THROW(l.erase(l.end()));
}
*/

/* //already tested
push: using insert
pop/clear: using erase
*/
TEST(ListTests, TestListPush_Pop_Erase) {
  s21::list<int> l{5, 6, 7, 9, 2, 1};
  l.push_back(52);
  EXPECT_EQ(l.size(), 7);
  EXPECT_EQ(l.back(), 52);
  l.pop_front();
  EXPECT_EQ(l.size(), 6);
  EXPECT_EQ(l.front(), 6);
  l.clear();
  EXPECT_EQ(l.size(), 0);
  l.push_front(5);
  l.push_front(4);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(l.front(), 4);
}

TEST(ListTests, TestListSwap){
  s21::list<int> sl1;
  s21::list<int> sl2{1, 5, 9};
  std::list<int> l1;
  std::list<int> l2{1, 5, 9};
  sl1.swap(sl2);
  l1.swap(l2);
  EXPECT_EQ(l1.empty(), sl1.empty());
  EXPECT_EQ(l2.empty(), sl2.empty());
  while(!l2.empty() && sl2.empty()){
    EXPECT_EQ(l2.front(), sl2.front());
    l2.pop_front();
    sl2.pop_front();
  }
}

TEST(ListTests, TestListSplice1) {
  s21::list<int> sl1{1, 2, 3, 7, 8, 90};
  s21::list<int> sl2{4, 5, 6};
  std::list<int> chl1{1, 2, 3, 7, 8, 90};
  std::list<int> chl2{4, 5, 6};
  s21::list<int>::iterator it = sl1.begin();
  auto chit = chl1.begin();
  for (int i{}; i < 3; i++) it++, chit++;
  sl1.splice(it, sl2);
  chl1.splice(chit, chl2);
  EXPECT_EQ(sl2.empty(), true);
  EXPECT_EQ(chl2.empty(), true);
  it = sl1.begin();
  chit = chl1.begin();
  for(; chit != chl1.end(); chit++, it++)
    EXPECT_EQ(*chit, *it); 
}


TEST(ListTests, TestListSplice2) {
  s21::list<int> sl1{};
  s21::list<int> sl2{4, 5, 6};
  std::list<int> chl{4, 5, 6};
  s21::list<int>::iterator it = sl1.begin();
  sl1.splice(it, sl2);
  EXPECT_EQ(sl2.empty(), true);
  it = sl1.begin();
  for(auto chit = chl.begin(); chit != chl.end() && it != sl1.end(); chit++, it++)
    EXPECT_EQ(*chit, *it);
}

TEST(ListTests, TestListSplice3) {
  s21::list<int> sl1{4, 5, 6};
  s21::list<int> sl2{};
  std::list<int> chl{4, 5, 6};
  s21::list<int>::iterator it = sl1.begin();
  sl1.splice(it, sl2);
  EXPECT_EQ(sl2.empty(), true);
  it = sl1.begin();
  for(auto chit = chl.begin(); chit != chl.end() && it != sl1.end(); chit++, it++)
    EXPECT_EQ(*chit, *it);
}
