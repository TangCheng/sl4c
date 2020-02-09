#include "list.h"

#include <gtest/gtest.h>

class ListTests : public testing::Test
{
public:
    char x;
    char y;
    char* value;
    List_T* list;
    void SetUp()
    {
        x = 'X';
        y = 'Y';
        value = NULL;
        list = NULL;
    }

    void tearDown()
    {
        List_free(&list);
    }
};

TEST_F(ListTests, should_return_a_list_has_one_element_after_first_push)
{
    list = List_push(list, &x);
    EXPECT_TRUE(list != NULL);
    int expectationLength = 1;
    int actualLength = List_length(list);
    EXPECT_EQ(actualLength, expectationLength);
    list = List_pop(list, (void**)&value);
    EXPECT_EQ(*value, x);
}

TEST_F(ListTests, should_return_a_list_has_two_elements_after_push_twice)
{
    list = List_push(list, &x);
    EXPECT_TRUE(list != NULL);
    list = List_push(list, &y);
    int expectationLength = 2;
    int actualLength = List_length(list);
    EXPECT_EQ(actualLength, expectationLength);
    list = List_pop(list, (void**)&value);
    EXPECT_EQ(*value, y);
}

TEST_F(ListTests, should_return_a_list_has_all_elements_when_append_one_list_to_another)
{
    list = List_push(list, &x);
    EXPECT_TRUE(list != NULL);
    List_T* tempList = NULL;
    tempList = List_push(tempList, &y);
    EXPECT_TRUE(tempList != NULL);
    list = List_append(list, tempList);
    tempList = NULL;
    int expectationLength = 2;
    int actualLength = List_length(list);
    EXPECT_EQ(actualLength, expectationLength);
    list = List_pop(list, (void**)&value);
    EXPECT_EQ(*value, x);
    list = List_pop(list, (void**)&value);
    EXPECT_EQ(*value, y);
}

TEST_F(ListTests, should_return_a_list_that_same_with_original_one_when_copy_it)
{
    List_T* originList = NULL;
    originList = List_push(originList, &x);
    originList = List_push(originList, &y);
    List_T* newList = List_copy(originList);
    EXPECT_TRUE(newList != NULL);
    int expectationLength = List_length(originList);
    int acutalLength = List_length(newList);
    EXPECT_EQ(acutalLength, expectationLength);
    char *originValue = NULL;
    originList = List_pop(originList, (void**)&originValue);
    EXPECT_TRUE(originValue != NULL);
    char *newValue = NULL;
    newList = List_pop(newList, (void**)&newValue);
    EXPECT_TRUE(newValue != NULL);
    EXPECT_EQ(*newValue, *originValue);
    List_free(&originList);
    List_free(&newList);
}

TEST_F(ListTests, should_reverse_order)
{
    list = List_push(list, &x);
    list = List_push(list, &y);
    list = List_reverse(list);
    EXPECT_TRUE(list != NULL);
    list = List_pop(list, (void**)&value);
    EXPECT_EQ(*value, x);
}

TEST_F(ListTests, should_get_array_with_ending_flag)
{
    list = List_push(list, &x);
    list = List_push(list, &y);
    void** array = List_toArray(list, NULL);
    EXPECT_TRUE(array != NULL);
    int listLength = List_length(list);
    int index;
    for (index = 0; index < listLength; index++) {
        char* actual = (char*)array[index];
        list = List_pop(list, (void**)&value);
        EXPECT_EQ(*actual, *value);
    }
    EXPECT_TRUE(array[listLength] == NULL);
}