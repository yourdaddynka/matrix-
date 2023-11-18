#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
#define eps 1e-7

TEST(Create, False) {
  ASSERT_THROW(S21Matrix test_2(0, -1), std::out_of_range);
}

TEST(SetValue, False) {
  S21Matrix test_2(10, 10);
  ASSERT_THROW(test_2(11, 11) = 1, std::out_of_range);
}

TEST(Constructors, CopyConstructor) {
  S21Matrix original(2, 3);
  original(1, 1) = 5.0;

  S21Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), 2);
  EXPECT_EQ(copy.GetCols(), 3);
  EXPECT_EQ(copy(1, 1), 5.0);
}

TEST(EqMatrix, True) {
  S21Matrix test_1(3, 3);
  S21Matrix test_2(3, 3);
  ASSERT_TRUE(test_1 == test_2);
}

TEST(EqMatrix, False) {
  S21Matrix test_1(3, 3);
  S21Matrix test_2(2, 2);
  ASSERT_FALSE(test_1 == test_2);
}

TEST(SumMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;
  test_1(1, 0) = -69.3;
  test_1(1, 1) = 0;

  test_2(0, 0) = -78.14;
  test_2(0, 1) = 0;
  test_2(1, 0) = -0.3;
  test_2(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  test_1.SumMatrix(test_2);
  ASSERT_TRUE(test_1 == result);
}

TEST(SumMatrix, SumMatrix5x5) {
  S21Matrix test_1(5, 5);
  S21Matrix test_2(5, 5);
  S21Matrix test_res(5, 5);

  test_1(0, 0) = 1;
  test_1(0, 1) = 2.0;
  test_1(0, 2) = 3.0;
  test_1(0, 3) = 4.0;
  test_1(0, 4) = 5.0;
  test_1(1, 0) = 6.0;
  test_1(1, 1) = -1.0;
  test_1(1, 2) = 7.0;
  test_1(1, 3) = 8.0;
  test_1(1, 4) = 0.0;
  test_1(2, 0) = -2.0;
  test_1(2, 1) = 3.0;
  test_1(2, 2) = 1.0;
  test_1(2, 3) = 0.0;
  test_1(2, 4) = -4.0;
  test_1(3, 0) = 7.0;
  test_1(3, 1) = 8.0;
  test_1(3, 2) = -5.0;
  test_1(3, 3) = 1.0;
  test_1(3, 4) = 2.0;
  test_1(4, 0) = 0.0;
  test_1(4, 1) = -3.0;
  test_1(4, 2) = 4.0;
  test_1(4, 3) = -2.0;
  test_1(4, 4) = 1.0;

  test_2(0, 0) = 2.0;
  test_2(0, 1) = 3.0;
  test_2(0, 2) = 3.0;
  test_2(0, 3) = 100.0;
  test_2(0, 4) = 33.0;
  test_2(1, 0) = 10.0;
  test_2(1, 1) = -100.0;
  test_2(1, 2) = 7.0;
  test_2(1, 3) = 5.0;
  test_2(1, 4) = 3.0;
  test_2(2, 0) = -30.0;
  test_2(2, 1) = 13.0;
  test_2(2, 2) = 31.0;
  test_2(2, 3) = 40.0;
  test_2(2, 4) = -48.0;
  test_2(3, 0) = 27.0;
  test_2(3, 1) = 38.0;
  test_2(3, 2) = -15.0;
  test_2(3, 3) = 11.0;
  test_2(3, 4) = 21.0;
  test_2(4, 0) = 110.0;
  test_2(4, 1) = -13.0;
  test_2(4, 2) = 34.0;
  test_2(4, 3) = -12.0;
  test_2(4, 4) = 31.0;

  test_res(0, 0) = 3.0;
  test_res(0, 1) = 5.0;
  test_res(0, 2) = 6.0;
  test_res(0, 3) = 104.0;
  test_res(0, 4) = 38.0;

  test_res(1, 0) = 16.0;
  test_res(1, 1) = -101.0;
  test_res(1, 2) = 14.0;
  test_res(1, 3) = 13.0;
  test_res(1, 4) = 3.0;

  test_res(2, 0) = -32.0;
  test_res(2, 1) = 16.0;
  test_res(2, 2) = 32.0;
  test_res(2, 3) = 40.0;
  test_res(2, 4) = -52.0;

  test_res(3, 0) = 34.0;
  test_res(3, 1) = 46.0;
  test_res(3, 2) = -20.0;
  test_res(3, 3) = 12.0;
  test_res(3, 4) = 23.0;

  test_res(4, 0) = 110.0;
  test_res(4, 1) = -16.0;
  test_res(4, 2) = 38.0;
  test_res(4, 3) = -14.0;
  test_res(4, 4) = 32.0;

  test_1.SumMatrix(test_2);
  ASSERT_TRUE(test_1 == test_res);
}

TEST(SumMatrix, False) {
  S21Matrix test_1(1, 2);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;

  test_2(0, 0) = -78.14;
  test_2(0, 1) = 0;
  test_2(1, 0) = -0.3;
  test_2(1, 1) = 2;

  EXPECT_THROW(test_1.SumMatrix(test_2), std::invalid_argument);
}

TEST(SumMatrix, SameValues) {
  S21Matrix test_1(2, 2);
  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;
  test_1(1, 0) = -69.3;
  test_1(1, 1) = 0;

  S21Matrix result(2, 2);
  result(0, 0) = 6.28;
  result(0, 1) = 1.12;
  result(1, 0) = -138.6;
  result(1, 1) = 0;
  test_1.SumMatrix(test_1);
  ASSERT_TRUE(test_1 == result);
}

TEST(SubMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3;
  test_2(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  test_1.SubMatrix(test_2);

  ASSERT_TRUE(test_1 == result);
}

TEST(SubMatrix, False) {
  S21Matrix test_1(1, 2);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3;
  test_2(1, 1) = 2;

  EXPECT_THROW(test_1.SubMatrix(test_2), std::invalid_argument);
}

TEST(SubMatrix, SameValues) {
  S21Matrix test_1(2, 2);
  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6;
  test_1(1, 1) = 0;

  S21Matrix result(2, 2);
  result(0, 0) = 0;
  result(0, 1) = 0;
  result(1, 0) = 0;
  result(1, 1) = 0;
  test_1.SubMatrix(test_1);
  ASSERT_TRUE(test_1 == result);
}

TEST(MulNumber, MultiplyByZero) {
  S21Matrix test_1(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = -78.14;
  test_1(0, 1) = 0;
  test_1(1, 0) = -0.3;
  test_1(1, 1) = 2;

  result(0, 0) = 0;
  result(0, 1) = 0;
  result(1, 0) = 0;
  result(1, 1) = 0;

  test_1.MulNumber(0);

  ASSERT_TRUE(test_1 == result);
}

TEST(MulNumber, MultiplyByNegativeNumber) {
  S21Matrix test_1(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = -78.14;
  test_1(0, 1) = 0;
  test_1(1, 0) = -0.3;
  test_1(1, 1) = 2;

  result(0, 0) = 781.4;
  result(0, 1) = 0;
  result(1, 0) = 3;
  result(1, 1) = -20;

  test_1.MulNumber(-10);

  ASSERT_TRUE(test_1 == result);
}

TEST(MulNumber, MultiplyByFractionalNumber) {
  S21Matrix test_1(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 1.5;
  test_1(0, 1) = 2.5;
  test_1(1, 0) = 3.0;
  test_1(1, 1) = 4.0;

  result(0, 0) = 4.5;
  result(0, 1) = 7.5;
  result(1, 0) = 9.0;
  result(1, 1) = 12.0;

  test_1.MulNumber(3);

  ASSERT_TRUE(test_1 == result);
}

TEST(MultNum, true) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  double num = 2;
  test_1(0, 0) = 1.0;
  test_1(0, 1) = 2.0;
  test_1(1, 0) = 3.0;
  test_1(1, 1) = 4.0;
  test_1.MulNumber(num);
  test_2(0, 0) = 2.0;
  test_2(0, 1) = 4.0;
  test_2(1, 0) = 6.0;
  test_2(1, 1) = 8.0;
  ASSERT_TRUE(test_1 == test_2);
}

TEST(MulMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6.6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3.5;
  test_2(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  test_1.MulMatrix(test_2);
  ASSERT_TRUE(test_1 == result);
}

TEST(MulMatrix, False) {
  S21Matrix test_1(2, 1);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3;
  test_1(1, 0) = -6.6;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3.5;
  test_2(1, 1) = 2;

  EXPECT_THROW(test_1.MulMatrix(test_2), std::invalid_argument);
}

TEST(MultMatrix, true) {
  S21Matrix test_1(1, 3);
  S21Matrix test_2(3, 1);

  test_1(0, 0) = 1.0;
  test_1(0, 1) = 2.0;
  test_1(0, 2) = 3.0;

  test_2(0, 0) = 4.0;
  test_2(1, 0) = 5.0;
  test_2(2, 0) = 6.0;

  test_1.MulMatrix(test_2);

  S21Matrix res(1, 1);
  res(0, 0) = 32;
  ASSERT_TRUE(test_1 == res);
}

TEST(MulMatrix, IdentityMatrix) {
  S21Matrix test_1(2, 2);
  test_1(0, 0) = 1;
  test_1(0, 1) = 0;
  test_1(1, 0) = 0;
  test_1(1, 1) = 1;

  S21Matrix test_2(2, 2);
  test_2(0, 0) = 2;
  test_2(0, 1) = 3;
  test_2(1, 0) = 4;
  test_2(1, 1) = 5;
  test_1.MulMatrix(test_2);
  ASSERT_TRUE(test_1 == test_2);
}

TEST(OperatorParentheses, True) {
  S21Matrix test_1(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6.6;
  test_1(1, 1) = 0;
  ASSERT_EQ(test_1(0, 1), 2);
}

TEST(OperatorParentheses, False) {
  S21Matrix test_1(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6.6;
  test_1(1, 1) = 0;
  ASSERT_NE(test_1(0, 1), 10);
}

TEST(OperatorPlus, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;
  test_1(1, 0) = -69.3;
  test_1(1, 1) = 0;

  test_2(0, 0) = -78.14;
  test_2(0, 1) = 0;
  test_2(1, 0) = -0.3;
  test_2(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((test_1 + test_2) == result);
}

TEST(OperatorPlus, ZeroMatrix) {
  S21Matrix test_1(2, 2);
  test_1(0, 0) = 0;
  test_1(0, 1) = 0;
  test_1(1, 0) = 0;
  test_1(1, 1) = 0;

  S21Matrix test_2(2, 2);
  test_2(0, 0) = 2;
  test_2(0, 1) = 3;
  test_2(1, 0) = 4;
  test_2(1, 1) = 5;

  ASSERT_TRUE((test_1 + test_2) == test_2);
}

TEST(OperatorMinus, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3;
  test_2(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((test_1 - test_2) == result);
}

TEST(OperatorMultiplyMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6.6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3.5;
  test_2(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((test_1 * test_2) == result);
}

TEST(OperatorMultiplyNumber, True) {
  S21Matrix test_1(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = -78.14;
  test_1(0, 1) = 0;
  test_1(1, 0) = -0.3;
  test_1(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((test_1 * 10) == result);
}

TEST(OperatorEqMatrix, True) {
  S21Matrix test_1(3, 3);
  S21Matrix test_2(1, 3);
  test_1 = test_2;
  ASSERT_TRUE(test_1 == test_2);
}

TEST(OperatorSumMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;
  test_1(1, 0) = -69.3;
  test_1(1, 1) = 0;

  test_2(0, 0) = -78.14;
  test_2(0, 1) = 0;
  test_2(1, 0) = -0.3;
  test_2(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((test_1 += test_2) == result);
}

TEST(OperatorSumMatrix, False) {
  S21Matrix test_1(1, 2);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3.14;
  test_1(0, 1) = 0.56;

  test_2(0, 0) = -78.14;
  test_2(0, 1) = 0;
  test_2(1, 0) = -0.3;
  test_2(1, 1) = 2;

  EXPECT_THROW((test_1 += test_2), std::invalid_argument);
}

TEST(OperatorSubMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3;
  test_2(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((test_1 -= test_2) == result);
}

TEST(OperatorSubMatrix, False) {
  S21Matrix test_1(1, 2);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3;
  test_2(1, 1) = 2;

  EXPECT_THROW(test_1 -= test_2, std::invalid_argument);
}

TEST(OperatorMulNumber, True) {
  S21Matrix test_1(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = -78.14;
  test_1(0, 1) = 0;
  test_1(1, 0) = -0.3;
  test_1(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((test_1 *= 10) == result);
}

TEST(OperatorMulMatrix, True) {
  S21Matrix test_1(2, 2);
  S21Matrix test_2(2, 2);
  S21Matrix result(2, 2);

  test_1(0, 0) = 3;
  test_1(0, 1) = 2;
  test_1(1, 0) = -6.6;
  test_1(1, 1) = 0;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3.5;
  test_2(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((test_1 *= test_2) == result);
}

TEST(OperatorMulMatrix, False) {
  S21Matrix test_1(2, 1);
  S21Matrix test_2(2, 2);

  test_1(0, 0) = 3;
  test_1(1, 0) = -6.6;

  test_2(0, 0) = -7;
  test_2(0, 1) = 0;
  test_2(1, 0) = -3.5;
  test_2(1, 1) = 2;

  EXPECT_THROW(test_1 *= test_2, std::invalid_argument);
}

TEST(Transpose, True) {
  S21Matrix test_1(4, 3);
  S21Matrix result(3, 4);

  test_1(0, 0) = 7;
  test_1(0, 1) = -98;
  test_1(0, 2) = 0.5;
  test_1(1, 0) = 0;
  test_1(1, 1) = 5.4;
  test_1(1, 2) = 32;
  test_1(2, 0) = 3.12;
  test_1(2, 1) = 2323;
  test_1(2, 2) = 23;
  test_1(3, 0) = -78;
  test_1(3, 1) = 476.4;
  test_1(3, 2) = 21;

  result(0, 0) = 7;
  result(0, 1) = 0;
  result(0, 2) = 3.12;
  result(0, 3) = -78;
  result(1, 0) = -98;
  result(1, 1) = 5.4;
  result(1, 2) = 2323;
  result(1, 3) = 476.4;
  result(2, 0) = 0.5;
  result(2, 1) = 32;
  result(2, 2) = 23;
  result(2, 3) = 21;
  S21Matrix res = test_1.Transpose();
  ASSERT_TRUE(res == result);
}

TEST(Transpose, IdentityMatrix) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 0;
  matrix(0, 2) = 0;
  matrix(1, 0) = 0;
  matrix(1, 1) = 1;
  matrix(1, 2) = 0;
  matrix(2, 0) = 0;
  matrix(2, 1) = 0;
  matrix(2, 2) = 1;

  ASSERT_TRUE(matrix.Transpose() == matrix);
}

TEST(Transpose, Sum4x4) {
  S21Matrix test_1(4, 3);
  S21Matrix result(3, 4);

  test_1(0, 0) = 7;
  test_1(0, 1) = -98;
  test_1(0, 2) = 0.5;
  test_1(1, 0) = 0;
  test_1(1, 1) = 5.4;
  test_1(1, 2) = 32;
  test_1(2, 0) = 3.12;
  test_1(2, 1) = 2323;
  test_1(2, 2) = 23;
  test_1(3, 0) = -78;
  test_1(3, 1) = 476.4;
  test_1(3, 2) = 21;

  result(0, 0) = 7;
  result(0, 1) = 0;
  result(0, 2) = 3.12;
  result(0, 3) = -78;
  result(1, 0) = -98;
  result(1, 1) = 5.4;
  result(1, 2) = 2323;
  result(1, 3) = 476.4;
  result(2, 0) = 0.5;
  result(2, 1) = 32;
  result(2, 2) = 23;
  result(2, 3) = 21;
  S21Matrix res = test_1.Transpose();
  ASSERT_TRUE(res == result);
}

TEST(Determinant, Determinant1x1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 2;
  EXPECT_TRUE(matrix.Determinant() == 2);
}

TEST(Determinant, Determinant2x2) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 2;
  matrix(0, 1) = 2;
  matrix(1, 0) = 2;
  matrix(1, 1) = 3;

  EXPECT_TRUE(matrix.Determinant() == 2);
}

TEST(Determinant, Determinant3x3) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 2;
  matrix(0, 1) = 2;
  matrix(0, 2) = 2;
  matrix(1, 0) = 2;
  matrix(1, 1) = 3;
  matrix(1, 2) = 1;
  matrix(2, 0) = 3;
  matrix(2, 1) = 2;
  matrix(2, 2) = 5;

  EXPECT_NEAR(matrix.Determinant(), 2, std::numeric_limits<double>::epsilon());
}

TEST(Determinant, NonSquareMatrix) {
  S21Matrix matrix(2, 3);
  EXPECT_THROW(matrix.Determinant(), std::out_of_range);
}

TEST(Determinant4_NonSquareMatrix_Test, NonSquareMatrix) {
  S21Matrix matrix(2, 3);
  EXPECT_THROW(matrix.Determinant(), std::out_of_range);
}

TEST(CalcComplements, SquareMatrix1x1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 5;

  EXPECT_TRUE(matrix.CalcComplements()(0, 0) == 1);
}

TEST(CalcComplements, SquareMatrix2x2) {
  S21Matrix matrix1(2, 2), matrix2(2, 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 5;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = -5;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = 1;

  EXPECT_TRUE(matrix2 == matrix1.CalcComplements());
}

TEST(CalcComplements, SquareMatrix3x3) {
  S21Matrix matrix1(3, 3), matrix2(3, 3);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 2;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;

  matrix2(0, 0) = 0;
  matrix2(0, 1) = 10;
  matrix2(0, 2) = -20;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = -14;
  matrix2(1, 2) = 8;
  matrix2(2, 0) = -8;
  matrix2(2, 1) = -2;
  matrix2(2, 2) = 4;

  EXPECT_TRUE(matrix2.EqMatrix(matrix1.CalcComplements()));
}

TEST(CalcComplements, NonSquareMatrix) {
  S21Matrix matrix(4, 3);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TEST(InverseMatrix, SquareMatrix1x1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 2;
  EXPECT_TRUE(matrix.InverseMatrix()(0, 0) == 0.5);
}

TEST(InverseMatrix, SquareMatrix2x2) {
  S21Matrix matrix1(2, 2), matrix2(2, 2);

  matrix1(0, 0) = 3;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 5;
  matrix1(1, 1) = 0;

  matrix2(0, 0) = 0;
  matrix2(0, 1) = 0.2;
  matrix2(1, 0) = 0.5;
  matrix2(1, 1) = -0.3;

  EXPECT_TRUE(matrix2.EqMatrix(matrix1.InverseMatrix()));
}

TEST(InverseMatrix, SquareMatrix3x3) {
  S21Matrix matrix1(3, 3), matrix2(3, 3);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 2;
  matrix1(2, 0) = 1;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;

  matrix2(0, 0) = 0;
  matrix2(0, 1) = -0.5;
  matrix2(0, 2) = 1;
  matrix2(1, 0) = -0.25;
  matrix2(1, 1) = 0.25;
  matrix2(1, 2) = 0.25;
  matrix2(2, 0) = 0.5;
  matrix2(2, 1) = 0;
  matrix2(2, 2) = -0.5;

  EXPECT_TRUE(matrix2.EqMatrix(matrix1.InverseMatrix()));
}

TEST(InverseMatrix, ZeroMatrix) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 3;
  matrix(0, 1) = 3;
  matrix(1, 0) = 3;
  matrix(1, 1) = 3;

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrix, NonSquareMatrix) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = 6;
  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrix, False) {
  S21Matrix test_1(4, 3);
  S21Matrix result(3, 4);

  test_1(0, 0) = 7;
  test_1(0, 1) = -98;
  test_1(0, 2) = 0.5;
  test_1(1, 0) = 0;
  test_1(1, 1) = 5.4;
  test_1(1, 2) = 32;
  test_1(2, 0) = 3.12;
  test_1(2, 1) = 2323;
  test_1(2, 2) = 23;
  test_1(3, 0) = -78;
  test_1(3, 1) = 476.4;
  test_1(3, 2) = 21;

  EXPECT_THROW(test_1.InverseMatrix(), std::out_of_range);
}

TEST(InverseMatrix, TestMistake) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 0;

  ASSERT_THROW(matrix.InverseMatrix(), std::out_of_range);
}

TEST(InverseMatrix, TestException3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 1;
  matrix(1, 0) = 1;
  matrix(1, 1) = 1;

  ASSERT_THROW(matrix.InverseMatrix(), std::out_of_range);
}

TEST(InverseMatrix, TestException2) {
  S21Matrix matrix(2, 3);

  ASSERT_THROW(matrix.InverseMatrix(), std::out_of_range);
}

TEST(Get, True) {
  S21Matrix test_1(3, 3);

  test_1(0, 0) = 2;
  test_1(0, 1) = 5;
  test_1(0, 2) = 7;
  test_1(1, 0) = 6;
  test_1(1, 1) = 3;
  test_1(1, 2) = 4;
  test_1(2, 0) = 5;
  test_1(2, 1) = -2;
  test_1(2, 2) = -3;

  ASSERT_EQ(test_1.GetRows(), 3);
  ASSERT_EQ(test_1.GetCols(), 3);
}

TEST(Set, True) {
  S21Matrix test_1(3, 3);
  S21Matrix result(3, 2);

  test_1(0, 0) = 2;
  test_1(0, 1) = 5;
  test_1(0, 2) = 7;
  test_1(1, 0) = 6;
  test_1(1, 1) = 3;
  test_1(1, 2) = 4;
  test_1(2, 0) = 5;
  test_1(2, 1) = -2;
  test_1(2, 2) = -3;

  result(0, 0) = 2;
  result(0, 1) = 5;

  result(1, 0) = 6;
  result(1, 1) = 3;

  result(2, 0) = 5;
  result(2, 1) = -2;
  test_1.SetCols(2);

  ASSERT_TRUE(test_1 == result);

  S21Matrix test_2(3, 3);
  S21Matrix result_b(2, 3);

  test_2(0, 0) = 2;
  test_2(0, 1) = 5;
  test_2(0, 2) = 7;
  test_2(1, 0) = 6;
  test_2(1, 1) = 3;
  test_2(1, 2) = 4;
  test_2(2, 0) = 5;
  test_2(2, 1) = -2;
  test_2(2, 2) = -3;

  result_b(0, 0) = 2;
  result_b(0, 1) = 5;
  result_b(0, 2) = 7;
  result_b(1, 0) = 6;
  result_b(1, 1) = 3;
  result_b(1, 2) = 4;

  test_2.SetRows(2);
  ASSERT_TRUE(test_2 == result_b);
}

TEST(SetValue, OutOfBoundsRow) {
  S21Matrix matrix(10, 10);
  ASSERT_THROW(matrix(15, 3) = 1, std::out_of_range);
}

TEST(SetValue, SetNegative) {
  S21Matrix matrix(10, 10);
  ASSERT_NO_THROW(matrix(3, 3) = -5);
}

TEST(OperatorParentheses, InitialZero) {
  S21Matrix matrix(3, 3);
  ASSERT_TRUE(matrix(1, 2) < eps);
}

TEST(Constructors, DefaultConstructor) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(Constructors, CopyConstructor2) {
  S21Matrix test_1(3, 3);
  test_1(0, 0) = 4;
  test_1(0, 1) = 7;
  test_1(0, 2) = 2;
  test_1(1, 0) = 3;
  test_1(1, 1) = 1;
  test_1(1, 2) = 8;
  test_1(2, 0) = 5;
  test_1(2, 1) = 6;
  test_1(2, 2) = 9;
  S21Matrix test_2(test_1);
  ASSERT_TRUE(test_1 == test_2);
}

TEST(OperatorAssign, AssignValues) {
  S21Matrix test_1(3, 3);
  test_1(0, 0) = 4;
  test_1(0, 1) = 7;
  test_1(0, 2) = 2;
  test_1(1, 0) = 3;
  test_1(1, 1) = 1;
  test_1(1, 2) = 8;
  test_1(2, 0) = 5;
  test_1(2, 1) = 6;
  test_1(2, 2) = 9;

  S21Matrix test_2(3, 3);

  test_2 = test_1;

  ASSERT_TRUE(test_1 == test_2);
}
TEST(S21MatrixTest, MoveConstructorTest) {
  S21Matrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;
  S21Matrix m2(std::move(m1));
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(0, 2), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(m2(1, 2), 6.0);
  EXPECT_DOUBLE_EQ(m2(2, 0), 7.0);
  EXPECT_DOUBLE_EQ(m2(2, 1), 8.0);
  EXPECT_DOUBLE_EQ(m2(2, 2), 9.0);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
}
TEST(S21MatrixTest, OutOfRangeAccess) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;
  const S21Matrix const_matrix(matrix);
  EXPECT_THROW(const_matrix(4, 0), std::out_of_range);
  EXPECT_THROW(const_matrix(0, 4), std::out_of_range);
  EXPECT_THROW(const_matrix(4, 4), std::out_of_range);
  EXPECT_THROW(const_matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(const_matrix(0, -1), std::out_of_range);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
