#include <gtest/gtest.h>

#include "vector.hpp"

using kp::Vector;

TEST(VectorTest, PushBackAndSize) {
    Vector<int> vec;
    EXPECT_EQ(vec.get_size(), 0);

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    EXPECT_EQ(vec.get_size(), 3);
}

TEST(VectorTest, HasItem) {
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(25);

    EXPECT_TRUE(vec.has_item(5));
    EXPECT_TRUE(vec.has_item(15));
    EXPECT_TRUE(vec.has_item(25));
    EXPECT_FALSE(vec.has_item(100));
}

TEST(VectorTest, Insert) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);

    EXPECT_TRUE(vec.insert(1, 2)); 
    EXPECT_EQ(vec.get_size(), 3);

    EXPECT_TRUE(vec.insert(0, 0));
    EXPECT_EQ(vec.get_size(), 4);

    EXPECT_TRUE(vec.insert(4, 4));
    EXPECT_EQ(vec.get_size(), 5);

    EXPECT_FALSE(vec.insert(10, 100));
}

TEST(VectorTest, RemoveFirst) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);

    EXPECT_TRUE(vec.remove_first(2));
    EXPECT_EQ(vec.get_size(), 3);

    EXPECT_TRUE(vec.has_item(2));

    EXPECT_FALSE(vec.remove_first(42));
}

TEST(VectorTest, CapacityExpansion) {
    Vector<int> vec;
    const int n = 10; 
    for (int i = 0; i < n; ++i) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.get_size(), n);

    for (int i = 0; i < n; ++i) {
        EXPECT_TRUE(vec.has_item(i));
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}