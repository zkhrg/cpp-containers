#include <stack>

#include "../test.h"

TEST(StackTests, TestDefaultConstructor1) {
  s21::stack<int> s1;
  std::stack<int> s2;

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(StackTests, TestDefaultConstructor2) {
  s21::stack<double> s1;
  std::stack<double> s2;

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(StackTests, TestInitializerListConstructor1) {
  s21::stack<int> s1 = {1, 2, 3};
  std::stack<int> s2;

  s2.push(1);
  s2.push(2);
  s2.push(3);

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  EXPECT_EQ(s1.top(), s2.top());
}

TEST(StackTests, TestInitializerListConstructor2) {
  s21::stack<double> s1 = {1.0, 2.0, 3.0};
  std::stack<double> s2;

  s2.push(1.0);
  s2.push(2.0);
  s2.push(3.0);

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  EXPECT_EQ(s1.top(), s2.top());
}

TEST(StackTests, TestInitializerListConstructor3) {
  s21::stack<int> s1 = {1, 2, 3};
  std::stack<int> s2({1, 2, 3});

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  EXPECT_EQ(s1.top(), s2.top());
}

TEST(StackTests, TestInitializerListConstructor4) {
  s21::stack<double> s1 = {1.0, 2.0, 3.0};
  std::stack<double> s2({1.0, 2.0, 3.0});

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  EXPECT_EQ(s1.top(), s2.top());
}

TEST(StackTests, TestCopyConstructor1) {
  s21::stack<int> q1 = {1, 2, 3};
  s21::stack<int> q2(q1);
  std::stack<int> q3({1, 2, 3});
  std::stack<int> q4(q3);

  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.size(), q3.size());
  EXPECT_EQ(q1.size(), q4.size());
  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q1.empty(), q3.empty());
  EXPECT_EQ(q1.empty(), q4.empty());
}

// TEST(QueueTests, TestCopyConstructor2) {
//   s21::stack<int> q1{1, 2, 3};
//   std::stack<int> q2({1, 2, 3});

//   s21::stack<int> q3;
//   std::stack<int> q4;

//   q3 = std::move(q1);
//   q4 = q2;

//   EXPECT_EQ(q1.size(), q2.size());
//   EXPECT_EQ(q1.size(), q3.size());
//   EXPECT_EQ(q1.size(), q4.size());
//   EXPECT_EQ(q1.empty(), q2.empty());
//   EXPECT_EQ(q1.empty(), q3.empty());
//   EXPECT_EQ(q1.empty(), q4.empty());
// }

TEST(StackTests, TestMoveConstructor1) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});
  s21::stack<int> q3;
  std::stack<int> q4;

  q3 = std::move(q1);
  q4 = std::move(q2);

  EXPECT_EQ(q3.top(), q4.top());
  EXPECT_EQ(q3.size(), q4.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestMoveConstructor2) {
  s21::stack<double> q1 = {1.0, 2.0, 3.0};
  std::stack<double> q2({1.0, 2.0, 3.0});
  s21::stack<double> q3;
  std::stack<double> q4;

  q3 = std::move(q1);
  q4 = std::move(q2);

  EXPECT_EQ(q1.empty(), q2.empty());
  EXPECT_EQ(q3.size(), q4.size());
  EXPECT_EQ(q3.top(), q4.top());
}

// TEST(QueueTests, TestAssignmentOperator1) {
//   s21::stack<int> q1 = {1, 2, 3};
//   std::stack<int> q2({1, 2, 3});
//   s21::stack<int> q3;
//   std::stack<int> q4;

//   q3 = q1;
//   q4 = q2;

//   EXPECT_EQ(q3.top(), q4.top());
//   EXPECT_EQ(q3.size(), q4.size());
//   EXPECT_EQ(q1.empty(), q2.empty());
// }

TEST(StackTests, TestTopMethod1) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  EXPECT_EQ(q1.top(), q2.top());
}

TEST(StackTests, TestTopMethod2) {
  s21::stack<double> q1 = {1.0, 2.0, 3.0};
  std::stack<double> q2({1.0, 2.0, 3.0});

  q1.pop();
  q2.pop();

  EXPECT_EQ(q1.top(), q2.top());
  EXPECT_EQ(q1.size(), q2.size());
}

TEST(StackTests, TestTopMethod3) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.push(4);
  q2.push(4);
  q1.push(5);
  q2.push(5);

  EXPECT_EQ(q1.top(), q2.top());
  EXPECT_EQ(q1.size(), q2.size());
}

TEST(StackTests, TestEmptyMethod1) {
  s21::stack<int> q1;
  std::stack<int> q2;

  EXPECT_TRUE(q1.empty());
  EXPECT_TRUE(q2.empty());
}

TEST(StackTests, TestEmptyMethod2) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  EXPECT_FALSE(q1.empty());
  EXPECT_FALSE(q2.empty());
}

TEST(StackTests, TestSizeMethod1) {
  s21::stack<int> q1;
  std::stack<int> q2;

  EXPECT_EQ(q1.size(), 0);
  EXPECT_EQ(q2.size(), 0);
}

TEST(StackTests, TestSizeMethod2) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  EXPECT_EQ(q1.size(), 3);
  EXPECT_EQ(q2.size(), 3);
}

TEST(StackTests, TestSizeMethod3) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.pop();
  q2.pop();

  EXPECT_EQ(q1.size(), 2);
  EXPECT_EQ(q2.size(), 2);
}

TEST(StackTests, TestSizeMethod4) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.push(4);
  q2.push(4);
  q1.push(5);
  q2.push(5);

  EXPECT_EQ(q1.size(), 5);
  EXPECT_EQ(q2.size(), 5);
}

TEST(StackTests, TestPushMethod1) {
  s21::stack<int> q1;
  std::stack<int> q2;

  q1.push(1);
  q2.push(1);
  q1.push(2);
  q2.push(2);
  q1.push(3);
  q2.push(3);

  EXPECT_EQ(q1.top(), q2.top());
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestPopMethod1) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.pop();
  q2.pop();

  EXPECT_EQ(q1.top(), q2.top());
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestPopMethod2) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.pop();
  q2.pop();
  q1.pop();
  q2.pop();

  EXPECT_EQ(q1.top(), q2.top());
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestPopMethod3) {
  s21::stack<int> q1 = {1, 2, 3};
  std::stack<int> q2({1, 2, 3});

  q1.pop();
  q1.pop();
  q2.pop();
  q2.pop();

  EXPECT_EQ(q1.top(), 1);
  EXPECT_EQ(q2.size(), 1);
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestSwapMethod1) {
  s21::stack<int> q1 = {1, 2, 3};
  s21::stack<int> q2 = {3, 2, 1};

  q1.swap(q2);

  EXPECT_EQ(q1.top(), 1);
  EXPECT_EQ(q2.top(), 3);
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestSwapMethod2) {
  s21::stack<int> q1 = {1, 2, 3};
  s21::stack<int> q2 = {3, 2, 1};

  q1.swap(q2);
  q2.swap(q1);

  EXPECT_EQ(q1.top(), 3);
  EXPECT_EQ(q2.top(), 1);
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.empty(), q2.empty());
}

TEST(StackTests, TestSwapMethod3) {
  s21::stack<int> q1 = {1, 2, 3};
  s21::stack<int> q2;
  std::stack<int> q3({1, 2, 3});
  std::stack<int> q4;

  q1.swap(q2);
  q3.swap(q4);

  EXPECT_EQ(q2.top(), 3);
  EXPECT_EQ(q4.top(), 3);
  EXPECT_EQ(q2.size(), q4.size());
  EXPECT_EQ(q1.empty(), q3.empty());
}

TEST(QueueTests, TestInsertManyFrontMethod1) {
  s21::stack<int> q1;
  EXPECT_TRUE(q1.empty());

  q1.insert_many_front(1, 2, 3);

  EXPECT_EQ(q1.top(), 3);
  EXPECT_EQ(q1.size(), 3);
  EXPECT_FALSE(q1.empty());
}