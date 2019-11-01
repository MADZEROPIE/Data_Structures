#include "List.h"

#include <gtest.h>

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int>);
}

TEST(List, can_create_list_with_positive_length)
{
	ASSERT_NO_THROW(List<int> (5));
}

TEST(List, cant_create_list_with_negative_length)
{
	ASSERT_ANY_THROW(List<int>(-5));
}

TEST(List, can_set_and_get_element)
{
	List<int> l (5);
	const int a = 7;
	l[0] = a;
	EXPECT_EQ(a, l[0]);

}