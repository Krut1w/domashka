#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "long_number.hpp"

using kp::LongNumber;

TEST(LongNumberTest, ConstructorAndEquality) {
    LongNumber a("12345");
    LongNumber b(a);
    LongNumber c("54321");
	LongNumber d("-54321");
    
    EXPECT_TRUE(a == b) << "Числа сравниваются неверно (равные числа неравны)";
    EXPECT_FALSE(a == c) << "Числа сравниваются неверно (неравные числа равны)";
	EXPECT_FALSE(a == d) << "Числа сравниваются неверно (числа с разными знаками равны)";
}

TEST(LongNumberTest, ConstructorAndOperatorEqual) {
	LongNumber a(1, 1);
	LongNumber b("12345");
	a = "12345";
	LongNumber c;
	c = b;
	
	EXPECT_TRUE(a == b) << "Равно не работает (строка)";
	EXPECT_TRUE(a == c) << "Равно не работает (класс)";
}

TEST(LongNumberTest, OperatorNotEqual) {
	LongNumber a("12345");
	LongNumber b("67890");
	LongNumber c("12345");
	
	EXPECT_TRUE(a != b) << "Неравно не работает (тру)";
	EXPECT_FALSE(a != c) << "Неравно не работает (фолз)";
}

TEST(LongNumberTest, Comparison) {
	LongNumber a("1111");
	LongNumber b("9999");
	LongNumber c("11111");
	LongNumber d("-9999");
	LongNumber e("-1111");
	
	EXPECT_TRUE(a < b) << "Сравнение не работает (1)";
	EXPECT_TRUE(c > a) << "Сравнение не работает (2)";
	EXPECT_TRUE(a > d) << "Сравнение не работает (3)";
	EXPECT_TRUE(d < e) << "Сравнение не работает (4)";
	EXPECT_TRUE(e > d) << "Сравнение не работает (5)";
}

TEST(LongNumberTest, Plus) {
	LongNumber a("100");
	LongNumber b("99");
	LongNumber c("-100");
	LongNumber d("-99");
	LongNumber a_plus_b("199");
	LongNumber a_plus_d("1");
	LongNumber c_plus_d("-199");
	LongNumber c_plus_b("-1");
	
	ASSERT_EQ(a + b, a_plus_b) << "Плюс не работает (1)";
	ASSERT_EQ(a + d, a_plus_d) << "Плюс не работает (2)";
	ASSERT_EQ(c + d, c_plus_d) << "Плюс не работает (3)";
	ASSERT_EQ(c + b, c_plus_b) << "Плюс не работает (4)";
}

TEST(LongNumberTest, Minus) {
	LongNumber a("100");
	LongNumber b("99");
	LongNumber c("-100");
	LongNumber d("-99");
	LongNumber a_minus_b("1");
	LongNumber a_minus_c("200");
	LongNumber b_minus_a("-1");
	LongNumber c_minus_d("-1");
	LongNumber c_minus_a("-200");
	LongNumber d_minus_c("1");
	
	ASSERT_EQ(a - b, a_minus_b) << "Минус не работает (1)";
	ASSERT_EQ(a - c, a_minus_c) << "Минус не работает (2)";
	ASSERT_EQ(b - a, b_minus_a) << "Минус не работает (3)";
	ASSERT_EQ(c - d, c_minus_d) << "Минус не работает (4)";
	ASSERT_EQ(c - a, c_minus_a) << "Минус не работает (5)";
	ASSERT_EQ(d - c, d_minus_c) << "Минус не работает (6)";
}

TEST(LongNumberTest, Multiplicate) {
	LongNumber a("20");
	LongNumber b("10");
	LongNumber c("-20");
	LongNumber d("-10");
	LongNumber a_mult_b("200");
	LongNumber a_mult_c("-400");
	LongNumber c_mult_d("200");
	
	ASSERT_EQ(a * b, a_mult_b) << "У(1)"; 
	ASSERT_EQ(a * c, a_mult_c) << "У(2)";
	ASSERT_EQ(c * d, c_mult_d) << "У(3)";
}

TEST(LongNumberTest, Divide) {
	LongNumber a("20");
	LongNumber b("3");
	LongNumber c("-20");
	LongNumber d("-3");
	LongNumber a_div_b("6");
	LongNumber a_div_c("-1");
	LongNumber c_div_d("6");
	LongNumber b_div_a("0");
	LongNumber d_div_a("0");
	
	ASSERT_EQ(a / b, a_div_b) << "Д(1)";
	ASSERT_EQ(a / c, a_div_c) << "Д(2)";
	ASSERT_EQ(c / d, c_div_d) << "Д(3)";
	ASSERT_EQ(b / a, b_div_a) << "Д(4)";
	ASSERT_EQ(d / a, d_div_a) << "Д(5)";
}

TEST(LongNumberTest, Remainder) {
	LongNumber a("20");
	LongNumber b("3");
	LongNumber c("-20");
	LongNumber d("-3");
	LongNumber a_rem_b("2");
	LongNumber b_rem_a("3");
	
	ASSERT_EQ(a % b, a_rem_b);
	ASSERT_EQ(b % a, b_rem_a);
}

TEST(LongNumberTest, Negative) {
	LongNumber a("-10");
	LongNumber b("10");
	
	EXPECT_TRUE(a.is_negative());
	EXPECT_FALSE(b.is_negative());
}
	
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}