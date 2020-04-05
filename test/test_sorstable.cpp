#include "Table.h"

#include <gtest.h>


TEST(SortedTable, can_create_sorted_table)
{
	ASSERT_NO_THROW(SorTable());
}

TEST(SortedTable, can_insert_elem)
{
	SorTable tab;
	ASSERT_NO_THROW(tab.Insert(Named_Polynom(Key("A"), "x+2")));

}

TEST(SortedTable, can_delete_elem)
{
	SorTable tab;
	EXPECT_NO_THROW(tab.Insert(Named_Polynom(Key("A"), "x+2")));
	ASSERT_NO_THROW(tab.Delete(Key("A")));
}

TEST(SortedTable, can_find_elem)
{
	SorTable tab;
	Named_Polynom pol(Key("A"), "x+2");
	EXPECT_NO_THROW(tab.Insert(pol));
	ASSERT_EQ(Key("A"),tab.Search(Key("A")).GetKey());
}

TEST(SortedTable, cant_find_nonexistent_elem)
{
	SorTable tab;
	Named_Polynom pol(Key("A"), "x+2");
	EXPECT_NO_THROW(tab.Insert(pol));
	ASSERT_ANY_THROW(tab.Search(Key("B")));
}