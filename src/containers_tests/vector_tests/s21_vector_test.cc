#include "test.h"
#include "vector"

TEST(VectorTests, TestDefaultVectorConstructor1) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestDefaultVectorConstructor2) {
  s21::vector<double> v1;
  std::vector<double> v2;
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestDefaultVectorConstructor3) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestInitializerListConstructor1) {
  s21::vector<int> v1 = {};
  std::vector<int> v2 = {};
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestInitializerListConstructor2) {
  s21::vector<std::string> v1 = {};
  std::vector<std::string> v2 = {};
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestInitializerListConstructor3) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestInitializerListConstructor4) {
  s21::vector<double> v1 = {};
  std::vector<double> v2 = {};
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestParameterizedVectorConstructor1) {
  size_t n = 0;
  s21::vector<int> v1(n);
  std::vector<int> v2(n);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestParameterizedVectorConstructor2) {
  size_t n = 5;
  s21::vector<double> v1(n);
  std::vector<double> v2(n);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestParameterizedVectorConstructor3) {
  size_t n = 100;
  s21::vector<float> v1(n);
  std::vector<float> v2(n);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestCopyConstructor1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  s21::vector<int> v2(v1);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestCopyConstructor2) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTests, TestCopyConstructor3) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::vector<int> v2(v1);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestCopyConstructor4) {
  s21::vector<int> v1 = {1};
  s21::vector<int> v2(v1);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1[0], v2[0]);
}

TEST(VectorTests, TestMoveConstructor1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  size_t tmp_size = v1.size();
  size_t tmp_capacity = v1.capacity();
  s21::vector<int> v2(std::move(v1));

  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 0);
  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(tmp_size, v2.size());
  EXPECT_EQ(tmp_capacity, v2.capacity());

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], i + 1);
  }
}

TEST(VectorTests, TestMoveConstructor2) {
  s21::vector<int> v1(5);
  s21::vector<int> v2(std::move(v1));

  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 0);
  EXPECT_TRUE(v1.empty());
  EXPECT_EQ(v1.data(), nullptr);

  EXPECT_EQ(v2.size(), 5);
  EXPECT_EQ(v2.capacity(), 5);
  EXPECT_FALSE(v2.empty());
}

TEST(VectorTests, TestOperatorEqual1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  s21::vector<int> v2;

  v2 = v1;

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_EQ(v1.capacity(), v2.capacity());

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestOperatorEqual2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  s21::vector<int> v2 = {6, 7, 8, 9, 10};

  v1 = std::move(v2);
  EXPECT_EQ(v1.size(), 5);
  EXPECT_EQ(v1.capacity(), 5);
  EXPECT_EQ(v2.size(), 0);
  EXPECT_EQ(v2.capacity(), 0);

  for (size_t i = 0; i != v1.size(); ++i) {
    EXPECT_EQ(v1[i], i + 6);
  }
}

TEST(VectorTests, TestMethodAt1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.at(0), v2.at(0));
  EXPECT_EQ(v1.at(1), v2.at(1));
  EXPECT_EQ(v1.at(2), v2.at(2));
  EXPECT_EQ(v1.at(3), v2.at(3));
  EXPECT_EQ(v1.at(4), v2.at(4));
}

TEST(VectorTests, TestMethodAt2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1.at(5), std::out_of_range);
  EXPECT_THROW(v2.at(5), std::out_of_range);
}

TEST(VectorTests, TestMethodAt3) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_THROW(v1.at(0), std::out_of_range);
  EXPECT_THROW(v2.at(0), std::out_of_range);
}

TEST(VectorTests, TestMethodAt4) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1.at(-1), std::out_of_range);
  EXPECT_THROW(v2.at(-1), std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1[0], v2[0]);
  EXPECT_EQ(v1[1], v2[1]);
  EXPECT_EQ(v1[2], v2[2]);
  EXPECT_EQ(v1[3], v2[3]);
  EXPECT_EQ(v1[4], v2[4]);
}

TEST(VectorTests, TestOperatorBracket2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1[5], std::out_of_range);
  EXPECT_THROW(v2[5], std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket3) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_THROW(v1[0], std::out_of_range);
  EXPECT_THROW(v2[0], std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket4) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1[-1], std::out_of_range);
  EXPECT_THROW(v2[-1], std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket5) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1[0], v2[0]);
  EXPECT_EQ(v1[1], v2[1]);
  EXPECT_EQ(v1[2], v2[2]);
  EXPECT_EQ(v1[3], v2[3]);
  EXPECT_EQ(v1[4], v2[4]);
}

TEST(VectorTests, TestOperatorBracket6) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1[5], std::out_of_range);
  EXPECT_THROW(v2[5], std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket7) {
  const s21::vector<int> v1;
  const std::vector<int> v2;

  EXPECT_THROW(v1[0], std::out_of_range);
  EXPECT_THROW(v2[0], std::out_of_range);
}

TEST(VectorTests, TestOperatorBracket8) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_THROW(v1[-1], std::out_of_range);
  EXPECT_THROW(v2[-1], std::out_of_range);
}

TEST(VectorTests, TestMethodFront1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.front(), v2.front());
  EXPECT_EQ(v1.front(), 1);
}

TEST(VectorTests, TestMethodFront2) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_THROW(v1.front(), std::out_of_range);
  EXPECT_THROW(v2.front(), std::out_of_range);
}

TEST(VectorTests, TestMethodBack1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.back(), v2.back());
  EXPECT_EQ(v1.back(), 5);
}

TEST(VectorTests, TestMethodBack2) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_THROW(v1.back(), std::out_of_range);
  EXPECT_THROW(v2.back(), std::out_of_range);
}

TEST(VectorTests, TestMethodData1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.data(), *v2.data());
}

TEST(VectorTests, TestMethodData2) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestMethodData3) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.data(), *v2.data());
}

TEST(VectorTests, TestMethodData4) {
  const s21::vector<int> v1;
  const std::vector<int> v2;

  EXPECT_EQ(v1.data(), nullptr);
  EXPECT_EQ(v2.data(), nullptr);
}

TEST(VectorTests, TestMethodBegin1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.begin(), *v2.begin());
}

TEST(VectorTests, TestMethodBegin2) {
  s21::vector<int> v1;

  EXPECT_EQ(v1.begin(), v1.end());
}

TEST(VectorTests, TestMethodEnd1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.end(), *v2.end());
}

TEST(VectorTests, TestMethodEnd2) {
  s21::vector<int> v1;

  EXPECT_EQ(v1.end(), v1.begin());
}

TEST(VectorTests, TestMethodCbegin1) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.cbegin(), *v2.cbegin());
}

TEST(VectorTests, TestMethodCbegin2) {
  const s21::vector<int> v1;

  EXPECT_EQ(v1.cbegin(), v1.cend());
}

TEST(VectorTests, TestMethodCend1) {
  const s21::vector<int> v1 = {1, 2, 3, 4, 5};
  const std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(*v1.cend(), *v2.cend());
}

TEST(VectorTests, TestMethodCend2) {
  const s21::vector<int> v1;

  EXPECT_EQ(v1.cend(), v1.cbegin());
}

TEST(VectorTests, TestMethodEmpty1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTests, TestMethodEmpty2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.empty(), v2.empty());
  EXPECT_FALSE(v1.empty());
}

TEST(VectorTests, TestMethodSize1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 0);
}

TEST(VectorTests, TestMethodSize2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 5);
}

TEST(VectorTests, TestMethodSize3) {
  s21::vector<double> v1 = {1, 2, 3, 4, 5};
  std::vector<double> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 5);
}

TEST(VectorTests, TestMethodMaxSize1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_EQ(v1.max_size(), v2.max_size());
}

TEST(VectorTests, TestMethodMaxSize2) {
  s21::vector<double> v1 = {1, 2, 3, 4, 5};
  std::vector<double> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.max_size(), v2.max_size());
}

TEST(VectorTests, TestMethodReserve1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.reserve(10);
  v2.reserve(10);

  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.capacity(), 10);
}

TEST(VectorTests, TestMethodReserve2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  v1.reserve(10);
  v2.reserve(10);

  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.capacity(), 10);
}

TEST(VectorTests, TestMethodReserve3) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_THROW(v1.reserve(99999999999999999), std::length_error);
  EXPECT_THROW(v2.reserve(99999999999999999), std::length_error);
}

TEST(VectorTests, TestMethodReserve4) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  size_t tmp_capacity1 = v1.capacity();
  size_t tmp_capacity2 = v2.capacity();

  v1.reserve(2);
  v2.reserve(2);

  EXPECT_EQ(v1.capacity(), tmp_capacity1);
  EXPECT_EQ(v2.capacity(), tmp_capacity2);
}

TEST(VectorTests, TestMethodCapacity1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.capacity(), 0);
}

TEST(VectorTests, TestMethodCapacity2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.capacity(), 5);
}

TEST(VectorTests, TestMethodShrinkToFit1) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.shrink_to_fit();
  v2.shrink_to_fit();

  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.capacity(), 0);
}

TEST(VectorTests, TestMethodShrinkToFit2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  v1.reserve(10);
  v2.reserve(10);
  EXPECT_EQ(v1.capacity(), 10);
  EXPECT_EQ(v2.capacity(), 10);
  EXPECT_EQ(v1.capacity(), v2.capacity());

  v1.shrink_to_fit();
  v2.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), 5);
  EXPECT_EQ(v2.capacity(), 5);
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTests, TestMethodClear1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  v1.clear();
  v2.clear();

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.begin(), v1.end());
}

TEST(VectorTests, TestMethodClear2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  size_t tmp_size1 = v1.size();
  size_t tmp_size2 = v2.size();
  size_t tmp_capacity1 = v1.capacity();
  size_t tmp_capacity2 = v2.capacity();

  v1.clear();
  v2.clear();

  EXPECT_EQ(v1.size(), 0);
  EXPECT_LT(v1.size(), tmp_size1);
  EXPECT_EQ(v1.capacity(), tmp_capacity1);

  EXPECT_EQ(v2.size(), 0);
  EXPECT_LT(v2.size(), tmp_size2);
  EXPECT_EQ(v2.capacity(), tmp_capacity2);
}

TEST(VectorTests, TestMethodInsert1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  v1.insert(v1.begin(), 0);
  v2.insert(v2.begin(), 0);

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 6);
  EXPECT_EQ(v1[0], 0);
  EXPECT_EQ(v2[0], 0);

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestMethodInsert2) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  auto it = v1.insert(v1.begin() + 2, 0);
  auto it2 = v2.insert(v2.begin() + 2, 0);

  EXPECT_EQ(it, v1.begin() + 2);
  EXPECT_EQ(it2, v2.begin() + 2);
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 6);
  EXPECT_EQ(v1[2], 0);
  EXPECT_EQ(v2[2], 0);

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestMethodInsert3) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  auto tmp_capacity1 = v1.capacity();
  auto tmp_capacity2 = v2.capacity();

  auto it = v1.insert(v1.end(), 8);
  auto it2 = v2.insert(v2.end(), 8);

  EXPECT_EQ(v1.capacity(), tmp_capacity1 * 2);
  EXPECT_EQ(v2.capacity(), tmp_capacity2 * 2);

  EXPECT_EQ(it, v1.end());
  EXPECT_EQ(it2, v2.end());
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.size(), 6);
  EXPECT_EQ(v1.capacity(), v2.capacity());

  EXPECT_EQ(v1[5], 8);
  EXPECT_EQ(v2[5], 8);

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTests, TestMethodErase1) {
  s21::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};

  v1.erase(v1.begin());
  v2.erase(v2.begin());

  EXPECT_EQ(v1.size(), 4);
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1[0], 2);
  EXPECT_EQ(v2[0], 2);

  for (size_t i = 0; i != v1.size() && i != v2.size(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}