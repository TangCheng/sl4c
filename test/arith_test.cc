#include "arith.h"

#include <gtest/gtest.h>

class ArithTests : public testing::Test
{
public:
    void FunctionMaxTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_max(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
    void FunctionMinTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_min(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
    void FunctionDivTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_div(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
    void FunctionModTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_mod(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
    void FunctionFloorTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_floor(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
    void FunctionCeilingTest(int integer1, int integer2, int expectation)
    {
        int actual = Arith_ceiling(integer1, integer2);
        EXPECT_EQ(actual, expectation);
    }
};

TEST_F(ArithTests, should_return_max_one_when_given_two_positive_integers_that_unequal)
{
    FunctionMaxTest(100, 1, 100);
}

TEST_F(ArithTests, should_return_max_one_when_given_two_negative_integers_that_unequal)
{
    FunctionMaxTest(-100, -1, -1);
}

TEST_F(ArithTests, should_return_positive_one_when_given_one_positive_integer_and_one_negative_integer)
{
    FunctionMaxTest(100, -100, 100);
}

TEST_F(ArithTests, should_return_positive_one_when_given_one_positive_integer_and_zero)
{
    FunctionMaxTest(100, 0, 100);
}

TEST_F(ArithTests, should_return_zero_when_given_one_negative_integer_and_zero)
{
    FunctionMaxTest(-100, 0, 0);
}

TEST_F(ArithTests, should_return_min_one_when_given_two_positive_integers_that_unequal)
{
    FunctionMinTest(100, 1, 1);
}

TEST_F(ArithTests, should_return_min_one_when_given_two_negative_integers_that_unequal)
{
    FunctionMinTest(-100, -1, -100);
}

TEST_F(ArithTests, should_return_negative_one_when_given_one_positive_integer_and_one_negative_integer)
{
    FunctionMinTest(100, -100, -100);
}

TEST_F(ArithTests, should_return_zero_when_given_one_positive_integer_and_zero)
{
    FunctionMinTest(100, 0, 0);
}

TEST_F(ArithTests, should_return_negative_one_when_given_one_negative_integer_and_zero)
{
    FunctionMinTest(-100, 0, -100);
}

TEST_F(ArithTests, should_return_zero_when_zero_divided_by_anything_except_zero)
{
    FunctionDivTest(0, -1, 0);
    FunctionDivTest(0, 1, 0);
}

TEST_F(ArithTests, should_return_2_when_given_13_divided_by_5)
{
    FunctionDivTest(13, 5, 2);
}

TEST_F(ArithTests, should_return_minus_3_when_given_minus_13_devied_by_5)
{
    FunctionDivTest(-13, 5, -3);
}

TEST_F(ArithTests, should_return_2_when_given_13_floored_by_5)
{
    FunctionFloorTest(13, 5, 2);
}

TEST_F(ArithTests, should_return_minus_3_when_given_minus_13_floord_by_5)
{
    FunctionFloorTest(-13, 5, -3);
}

TEST_F(ArithTests, should_return_3_when_given_13_ceiling_by_5)
{
    FunctionCeilingTest(13, 5, 3);
}

TEST_F(ArithTests, should_return_minus_2_when_given_minus_13_ceiling_by_5)
{
    FunctionCeilingTest(-13, 5, -2);
}
