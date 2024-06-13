#include "test.h"
#include <list>

TEST(ListTests, TestDefaultListConstructor1) {
  s21::list<int> l1;
  std::list<int> l2;
  EXPECT_EQ(l1.size(), l2.size());
  EXPECT_EQ(l1.empty(), true);
  EXPECT_EQ(l2.empty(), true);
}