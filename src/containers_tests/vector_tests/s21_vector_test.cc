#include "test.h"
#include "vector"

TEST(VectorTests, TestDefaultVectorConstructor1) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
  // EXPECT_EQ(v1.empty(), v2.empty());
}
TEST(VectorTests, TestParameterizedVectorConstructor2) {
  size_t n = 3;
  s21::vector<int> v1(n);
  std::vector<int> v2(n);

  EXPECT_EQ(v1.size(), v2.size());
  // EXPECT_EQ(v1.empty(), v2.empty());
}
TEST(VectorTests, TestDefaultVectorConstructor3) {
  size_t n = 5;
  s21::vector<int> v1(n);
  std::vector<int> v2(n);

  EXPECT_EQ(v1.size(), v2.size());
  // EXPECT_EQ(v1.empty(), v2.empty());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}