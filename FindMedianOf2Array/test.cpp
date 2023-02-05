#include <gtest/gtest.h>
#include "func.h"


TEST(MedianTest, TestWithOddSize)
{

    std::vector<int> a{ 1,3 };
    std::vector<int> b{ 2 };
    EXPECT_EQ(findMedianSortedArrays(a, b), 2.0);
}

TEST(MedianTest, TestWithEvenSize)
{

    std::vector<int> a{ 1,3 };
    std::vector<int> c{ 2,4 };
    EXPECT_EQ(findMedianSortedArrays(a, c), 2.5);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
