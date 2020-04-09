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

TEST(SortedTable, complex_test_1)
{
	SorTable tab;
	Key k1("Alice"), k2("Laura"), k3("Crow");
	Named_Polynom pol1(k1, "x+2"), pol2(k2, "y+2"), pol3(k3, "z+2");
	EXPECT_NO_THROW(tab.Insert(pol1));
	EXPECT_NO_THROW(tab.Insert(pol2));
	EXPECT_NO_THROW(tab.Insert(pol3));
	EXPECT_EQ(pol1.GetKey(), tab.Search(k1).GetKey());
	EXPECT_EQ(pol2.GetKey(), tab.Search(k2).GetKey());
	EXPECT_EQ(pol3.GetKey(), tab.Search(k3).GetKey());
}

TEST(SortedTable, complex_test_2)
{
	SorTable tab;
	Key k1("Alice"), k2("Laura"), k3("Crow"), k4("Fie");
	Named_Polynom pol1(k1, "x+2"), pol2(k2, "y+2"), pol3(k3, "z+2");
	EXPECT_NO_THROW(tab.Insert(pol1));
	EXPECT_NO_THROW(tab.Insert(pol2));
	EXPECT_NO_THROW(tab.Insert(pol3));
	
	EXPECT_ANY_THROW(tab.Search(k4));
	EXPECT_NO_THROW(tab.Delete(k2));
	EXPECT_EQ(pol1.GetKey(), tab.Search(k1).GetKey());
	EXPECT_EQ(pol3.GetKey(), tab.Search(k3).GetKey());
	EXPECT_ANY_THROW(tab.Search(k2));
}