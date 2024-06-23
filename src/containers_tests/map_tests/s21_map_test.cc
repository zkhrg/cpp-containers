#include <iostream>
#include <map>

#include "../test.h"

TEST(MapTests, TestMapFirst) {
  s21::map<int, int> m;
  EXPECT_EQ(m.insert(4, 5).second, true);
  EXPECT_EQ(m.insert(3, 3).second, true);
  EXPECT_EQ(m.insert(8, 1).second, true);
  EXPECT_EQ(m.insert(6, 6).second, true);
  EXPECT_EQ(m.insert(-5, -5).second, true);
  EXPECT_EQ(m.insert(7, -3).second, true);
  std::map<int, int> chm;
  chm.insert({4, 5});
  chm.insert({3, 3});
  chm.insert({8, 1});
  chm.insert({6, 6});
  chm.insert({-5, -5});
  chm.insert({7, -3});
  auto iter = chm.begin();
  auto it = m.begin();
  for (; it != m.end() && iter != chm.end(); it++, iter++) {
    EXPECT_EQ(it->second, iter->second);
  }
}

TEST(MapTests, TestMapSecond) {
  s21::map<int, int> m;
  EXPECT_EQ(m.insert({4, 5}).second, true);
  EXPECT_EQ(m.insert({3, 3}).second, true);
  EXPECT_EQ(m.insert({8, 1}).second, true);
  EXPECT_EQ(m.insert({6, 6}).second, true);
  EXPECT_EQ(m.insert({-5, -5}).second, true);
  EXPECT_EQ(m.insert({7, -3}).second, true);
  std::map<int, int> chm;
  chm.insert({4, 5});
  chm.insert({3, 3});
  chm.insert({8, 1});
  chm.insert({6, 6});
  chm.insert({-5, -5});
  chm.insert({7, -3});
  auto iter = chm.begin();
  auto it = m.begin();
  for (; it != m.end() && iter != chm.end(); it++, iter++) {
    EXPECT_EQ(it->second, iter->second);
  }
}