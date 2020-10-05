#include "gtest/gtest.h"

#include "converter.hpp"

typedef struct {
	std::string m_hex;
	std::string m_bin;
	std::string m_dec;
	uint8_t     m_val;
} data;

const std::array test_data = {
    //  | hex  |   binary    | decimal | value |
    data{"0xFF", "0b11111111", "0d255", 255}, //
    data{"0x00", "0b00000000", "0d0", 0},     //
    data{"0xEF", "0b11101111", "0d239", 239}, //
    data{"0x00", "0b00000000", "0d0", 0},     //
    data{"0x01", "0b00000001", "0d1", 1},     //
    data{"0x0E", "0b00001110", "0d14", 14},   //
    data{"0x0F", "0b00001111", "0d15", 15},   //
    data{"0x10", "0b00010000", "0d16", 16},   //
    data{"0xE0", "0b11100000", "0d224", 224}, //
    data{"0xF0", "0b11110000", "0d240", 240}  //
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
