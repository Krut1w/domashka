#include <gtest/gtest.h>
#include "shell_sort.hpp"

TEST(ShellSort, SortsNormalArray) {
    int arr[] = {5, 3, 8, 1, 2};
    biv::shell_sort(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 5);
    EXPECT_EQ(arr[4], 8);
}

TEST(ShellSort, AlreadySorted) {
    int arr[] = {1, 2, 3, 4, 5};
    biv::shell_sort(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[4], 5);
}

TEST(ShellSort, ReverseSorted) {
    int arr[] = {5, 4, 3, 2, 1};
    biv::shell_sort(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[4], 5);
}

TEST(ShellSort, SingleElement) {
    int arr[] = {42};
    biv::shell_sort(arr, 1);
    EXPECT_EQ(arr[0], 42);
}

TEST(ShellSort, WithNegatives) {
    int arr[] = {-3, 5, -1, 0, 2};
    biv::shell_sort(arr, 5);
    EXPECT_EQ(arr[0], -3);
    EXPECT_EQ(arr[1], -1);
    EXPECT_EQ(arr[2], 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}