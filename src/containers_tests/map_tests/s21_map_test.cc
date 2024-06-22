#include "../test.h"
#include <map>
#include <iostream>

TEST(MapTests, TestMapFirst) {
  s21::map<int, int> m;
  EXPECT_EQ(m.insert(4, 5).second, true);
  EXPECT_EQ(m.insert(3, 3).second, true);
  EXPECT_EQ(m.insert(8, 1).second, true);
  for(auto it = m.begin(); it != m.end(); it++) {
    std::cout << it->second << std::endl;
  }
}