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

TEST(PasswordTest, special_characters_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("###abc");
	ASSERT_EQ(3, actual);
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

TEST(PasswordTest, empty_string_mixed_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_uppercase) {
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEFG");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_uppercase_letter) {
	Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_lowercase_letter) {
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, minimal_mixed_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, numbers_only) {
	Password my_password;
	bool actual = my_password.has_mixed_case("123456");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, special_characters_only) {
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#$%^&*()");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_with_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("Abc123");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_with_special_chars) {
	Password my_password;
	bool actual = my_password.has_mixed_case("Abc!@#");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, uppercase_with_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC123");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, lowercase_with_numbers) {
	Password my_password;
	bool actual = my_password.has_mixed_case("abc123");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, uppercase_with_special_chars) {
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC!@#");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, lowercase_with_special_chars) {
	Password my_password;
	bool actual = my_password.has_mixed_case("abc!@#");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_complex) {
	Password my_password;
	bool actual = my_password.has_mixed_case("P@ssW0rd!");
	ASSERT_EQ(true, actual);
}


TEST(PasswordTest, unique_lower_happy) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("abc");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_upper_happy) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("ABC");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_lowercase_repeated) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("aaa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_uppercase_repeated) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("AAA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_mixed_case_aA) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("aA");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, unique_mixed_case_Aa) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("Aa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, unique_empty_string) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, unique_mixed_case_alternating) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("AaBbCc");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, unique_mixed_case_reversed) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("aAbBcC");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, unique_with_numbers) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("abc123");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, unique_with_repeated_numbers) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("111222333");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_special_characters) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("!@#$%");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, unique_repeated_special_characters) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("!!!@@@###");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_mixed_with_special_chars) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("Aa!Bb@");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, unique_complex_password) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("P@ssW0rd!");
	ASSERT_EQ(8, actual);
}

TEST(PasswordTest, unique_all_same_special) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("####");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_spaces) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("a b c");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, unique_mixed_case_with_duplicates) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("AaAaBbBb");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, unique_uppercase_lowercase_numbers_special) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("Aa1!");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, unique_single_character) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_whitespace_only) {
	Password my_password;
	unsigned int actual = my_password.unique_characters("   ");
	ASSERT_EQ(1, actual);
}