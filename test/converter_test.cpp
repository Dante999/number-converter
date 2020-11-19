#include "gtest/gtest.h"

#include "ascii_table.hpp"
#include "converter.hpp"

typedef struct {
	std::string m_ascii;
	std::string m_hex;
	std::string m_bin;
	std::string m_dec;
	uint8_t     m_val;
} data;

const std::array test_data = {
    //  | hex  |   binary    | decimal | value |
    data{ASCII_UNDEFINED, "0xFF", "0b11111111", "0d255", 255}, //
    // data{ASCII_UNDEFINED, "0x00", "0b00000000", "0d0", 0},     //
    data{ASCII_UNDEFINED, "0xEF", "0b11101111", "0d239", 239}, //
    data{"NUL", "0x00", "0b00000000", "0d0", 0},               //
    data{"SOH", "0x01", "0b00000001", "0d1", 1},               //
    data{"SO", "0x0E", "0b00001110", "0d14", 14},              //
    data{"SI", "0x0F", "0b00001111", "0d15", 15},              //
    data{"DLE", "0x10", "0b00010000", "0d16", 16},             //
    data{ASCII_UNDEFINED, "0xE0", "0b11100000", "0d224", 224}, //
    data{ASCII_UNDEFINED, "0xF0", "0b11110000", "0d240", 240}  //
};

TEST(Converter, to_hex)
{
	for (const auto &v : test_data) {

		const std::string val_expected = v.m_hex;

		std::string val_actual;

		Converter::to_hex(val_actual, v.m_val);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, to_decimal)
{
	for (const auto &v : test_data) {

		const std::string val_expected = v.m_dec;

		std::string val_actual;

		Converter::to_decimal(val_actual, v.m_val);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, to_binary)
{
	for (const auto &v : test_data) {

		const std::string val_expected = v.m_bin;

		std::string val_actual;

		Converter::to_binary(val_actual, v.m_val);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, to_ascii)
{
	for (const auto &v : test_data) {

		const std::string val_expected = v.m_ascii;

		std::string val_actual;

		Converter::to_ascii(val_actual, v.m_val);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, from_hex)
{
	for (const auto &v : test_data) {
		const uint8_t val_expected = v.m_val;

		uint8_t val_actual = Converter::parse(v.m_hex);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, from_binary)
{
	for (const auto &v : test_data) {
		const uint8_t val_expected = v.m_val;

		uint8_t val_actual = Converter::parse(v.m_bin);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, from_dec)
{
	for (const auto &v : test_data) {
		const uint8_t val_expected = v.m_val;

		uint8_t val_actual = Converter::parse(v.m_dec);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, from_ascii)
{
	typedef struct {
		uint8_t     m_val;
		std::string m_ascii;
	} ascii_testdata;

	const std::array td = {
	    ascii_testdata{32, " "},  ascii_testdata{40, "("},
	    ascii_testdata{63, "?"},  ascii_testdata{90, "Z"},
	    ascii_testdata{122, "z"}, ascii_testdata{126, "~"},
	};

	for (const auto &v : td) {
		const uint8_t val_expected = v.m_val;

		uint8_t val_actual = Converter::parse(v.m_ascii);

		EXPECT_EQ(val_expected, val_actual);
	}
}

TEST(Converter, GIVEN_negativeNumber_WHEN_fromDec_THEN_exception)
{
	try {
		Converter::parse("0d256");

	} catch (const char *msg) {
		return;
	}
}
