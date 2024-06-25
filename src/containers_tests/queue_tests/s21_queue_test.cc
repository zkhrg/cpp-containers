#include <queue>

#include "../test.h"

TEST(QueueTests, TestDefaultConstructor1) {
  s21::queue<int> q1;
  std::queue<int> q2;

  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(QueueTests, TestDefaultConstructor2) {
  s21::queue<double> q1;
  std::queue<double> q2;

  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(QueueTests, TestInitializerListConstructor1) {
  s21::queue<int> q1 = {1, 2, 3};
  std::queue<int> q2({1, 2, 3});

  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}