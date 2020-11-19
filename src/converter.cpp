#include "converter.hpp"

#include <exception>

#include "ascii_table.hpp"

constexpr size_t TMP_SIZE = 20;

const int         Converter::PREFIX_LENGTH  = 2;
const std::string Converter::PREFIX_HEX     = "0x";
const std::string Converter::PREFIX_BINARY  = "0b";
const std::string Converter::PREFIX_DECIMAL = "0d";

constexpr char get_bit(uint8_t byte, uint8_t bit)
{
	return (byte & (1 << bit) ? '1' : '0');
}

uint8_t Converter::parse(const std::string &input)
{
	if (input.size() == 1) {
		return Converter::from_ascii(input);
	}

	const std::string prefix = input.substr(0, 2);
	const std::string value  = input.substr(2);

	if (prefix == PREFIX_DECIMAL) {
		return Converter::from_decimal(value);
	}
	else if (prefix == PREFIX_HEX) {
		return Converter::from_hex(value);
	}
	else if (prefix == PREFIX_BINARY) {
		return Converter::from_binary(value);
	}
	else {
		throw "unkown prefix";
	}

	return 0;
}

void Converter::to_hex(std::string &result, uint8_t value)
{
	char tmp[TMP_SIZE];
	sprintf(tmp, "0x%02X", value);
	result = tmp;
}

void Converter::to_ascii(std::string &result, uint8_t value)
{
	char tmp[TMP_SIZE];
	sprintf(tmp, "%s", value < 128 ? ascii_table[value] : ASCII_UNDEFINED);
	result = tmp;
}

void Converter::to_decimal(std::string &result, uint8_t value)
{
	char tmp[TMP_SIZE];
	sprintf(tmp, "0d%d", value); // decimal
	result = tmp;
}

void Converter::to_binary(std::string &result, uint8_t value)
{
	char tmp[TMP_SIZE];
	sprintf(tmp, "0b%c%c%c%c%c%c%c%c", get_bit(value, 7), get_bit(value, 6),
	        get_bit(value, 5), get_bit(value, 4), get_bit(value, 3),
	        get_bit(value, 2), get_bit(value, 1), get_bit(value, 0));

	result = tmp;
}

uint8_t Converter::from_hex(const std::string &value)
{
	unsigned int i;

	sscanf(value.c_str(), "%X", &i);

	if (255 < i) {
		throw "number negative or greater than 255";
	}
	else {
		return static_cast<uint8_t>(i);
	}
}

uint8_t Converter::from_ascii(const std::string &value)
{
	char c = value.at(0);

	return static_cast<uint8_t>(c);
}

uint8_t Converter::from_decimal(const std::string &value)
{
	int i;

	sscanf(value.c_str(), "%d", &i);

	if (i < 0 || 255 < i) {
		throw "number negative or greater than 255";
	}
	else {
		return static_cast<uint8_t>(i);
	}
}

uint8_t Converter::from_binary(const std::string &value)
{
	constexpr uint8_t expected_length = 8;

	uint8_t retval = 0;

	if (value.length() != expected_length) {
		throw "value has not the expected length of 8";
	}

	for (uint8_t i = 0; i < expected_length; i++) {

		if (value.at(i) == '1')
			retval |= static_cast<uint8_t>((1 << (7 - i)));
	}

	return retval;
}
