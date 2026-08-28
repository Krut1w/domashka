#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using kp::DoublyLinkedList;

TEST(DoublyLinkedListTest, PushBackAndSize) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.get_size(), 0);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.get_size(), 3);
}

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(15);
    list.push_back(25);

    EXPECT_TRUE(list.has_item(5));
    EXPECT_TRUE(list.has_item(15));
    EXPECT_TRUE(list.has_item(25));
    EXPECT_FALSE(list.has_item(100));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(2);

    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item(2));

    EXPECT_FALSE(list.remove_first(42));
}

TEST(DoublyLinkedListTest, RemoveFirstEdgeCases) {
    DoublyLinkedList<int> list;

    EXPECT_FALSE(list.remove_first(1));

    list.push_back(42);
    EXPECT_TRUE(list.remove_first(42));
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(42));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}