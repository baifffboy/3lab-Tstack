#include "postfix.h"
#include <gtest.h>

TEST(TArithmetic, can_create_TArithmetic)
{
	ASSERT_NO_THROW(TArithmetic m("5"));
}

TEST(TArithmetic, can_do_plus_TArithmetic)
{
	TArithmetic m("1+2");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, plus_is_true_in_TArithmetic)
{
	TArithmetic m("1+2");
	ASSERT_EQ(m.proverka_testov(), 3);
}

TEST(TArithmetic, can_do_sub_TArithmetic)
{
	TArithmetic m("2 - 1");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, sub_is_true_in_TArithmetic)
{
	TArithmetic m("1 - 2");
	ASSERT_EQ(m.proverka_testov(), -1);
}

TEST(TArithmetic, can_do_mult_TArithmetic)
{
	TArithmetic m("7 * 5");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, mult_is_true_in_TArithmetic)
{
	TArithmetic m("7 * 5");
	ASSERT_EQ(m.proverka_testov(), 35);
}

TEST(TArithmetic, can_do_div_TArithmetic)
{
	TArithmetic m("6/3");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, div_is_true_in_TArithmetic)
{
	TArithmetic m("6/2");
	ASSERT_EQ(m.proverka_testov(), 3);
}

TEST(TArithmetic, can_do_stepen_TArithmetic)
{
	TArithmetic m("4^3");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, stepen_is_true_in_TArithmetic)
{
	TArithmetic m("4^3");
	ASSERT_EQ(m.proverka_testov(), 64);
}

TEST(TArithmetic, multi_stepen_is_true_in_TArithmetic)
{
	TArithmetic m("3^2^2");
	ASSERT_EQ(m.proverka_testov(), 81);
}

TEST(TArithmetic, can_do_bkt_TArithmetic)
{
	TArithmetic m("3*(4+3)");
	ASSERT_NO_THROW(m.proverka_testov());
}

TEST(TArithmetic, bkt_is_true_in_TArithmetic)
{
	TArithmetic m("3*(4+3)");
	ASSERT_EQ(m.proverka_testov(), 21);
}