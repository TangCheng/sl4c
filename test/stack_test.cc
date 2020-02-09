#include "stack.h"

#include <gtest/gtest.h>

class StackTests : public testing::Test
{
public:

};

TEST_F(StackTests, should_return_empty_stack_when_initialized)
{
    Stack_T* s = Stack_new();
    EXPECT_NE(s, nullptr);
    EXPECT_TRUE(Stack_empty(s));
    Stack_free(&s);
}

TEST_F(StackTests, should_not_empty_after_push_some_value)
{
    Stack_T* s = Stack_new();
    EXPECT_NE(s, nullptr);
    Stack_push(s, nullptr);
    EXPECT_FALSE(Stack_empty(s));
    Stack_free(&s);
}

TEST_F(StackTests, should_pop_all_the_values_in_reverse_order)
{
    Stack_T* s = Stack_new();
    EXPECT_NE(s, nullptr);
    int value[2] = {1, 2};
    Stack_push(s, &value[0]);
    Stack_push(s, &value[1]);
    int* expectation = &value[1];
    int* actual = (int*)Stack_pop(s);
    EXPECT_EQ(actual, expectation);
    expectation = &value[0];
    actual = (int*)Stack_pop(s);
    EXPECT_EQ(actual, expectation);
    EXPECT_TRUE(Stack_empty(s));
    Stack_free(&s);
}