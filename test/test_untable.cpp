#include "Table.h"

#include <gtest.h>

TEST(UnsortedTable, can_create_unsorted_table)
{
	ASSERT_NO_THROW(UnsTable());
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

TEST(UnsortedTable, can_find_elem)
{
	UnsTable tab;
	Named_Polynom pol(Key("A"), "x+2");
	EXPECT_NO_THROW(tab.Insert(pol));
	ASSERT_EQ(Key("A"), tab.Search(Key("A")).GetKey());
}

TEST(UnsortedTable, cant_find_nonexistent_elem)
{
	UnsTable tab;
	Named_Polynom pol(Key("A"), "x+2");
	EXPECT_NO_THROW(tab.Insert(pol));
	ASSERT_ANY_THROW(tab.Search(Key("B")));
}