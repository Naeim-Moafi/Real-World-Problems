#include <gtest/gtest.h>
#include "gcd.h"


class solutionTest : public ::testing::Test
{
protected:
	solution s;
};

TEST_F(solutionTest, gcdWorks)
{
	EXPECT_EQ(s.gcd(12, 6), 6);
	EXPECT_EQ(s.gcd(65, 13), 13);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
