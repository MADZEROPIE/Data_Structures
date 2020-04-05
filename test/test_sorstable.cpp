#include "Table.h"

#include <gtest.h>

TEST(UnsortedTable, can_create_unsorted_table)
{
	ASSERT_NO_THROW(UnsTable());
}
TEST(SortedTable, can_create_sorted_table)
{
	ASSERT_NO_THROW(SorTable());
}

TEST(UnsortedTable, can_insert_elem)
{
	UnsTable tab;
	ASSERT_NO_THROW(tab.Insert(Named_Polynom(Key("A"), "x+2")));

}

TEST(UnsortedTable, can_delete_elem)
{
	UnsTable tab;
	ASSERT_NO_THROW(tab.Insert(Named_Polynom(Key("A"), "x+2")));
	ASSERT_NO_THROW(tab.Delete(Key("A")));

}