/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}


TEST(PasswordTest, multiple_leading_chars)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaBcD");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, single_leading_char)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aBcD");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, alternating_case)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaAABcD");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, single_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("AaAaA");
	ASSERT_EQ(true, actual);
}