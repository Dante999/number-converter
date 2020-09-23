#include "converter.hpp"

const int         Converter::PREFIX_LENGTH  = 2;
const std::string Converter::PREFIX_HEX     = "0x";
const std::string Converter::PREFIX_BINARY  = "0b";
const std::string Converter::PREFIX_DECIMAL = "0d";

uint8_t Converter::parse(const std::string &input)
{
	std::string prefix = input.substr(0, 2);
	std::string value  = input.substr(2);

	if (prefix == PREFIX_DECIMAL) {
		int number = std::atoi(value.c_str());
		(void)number;
	}

	return 0;
}

void Converter::to_hex(std::string &result, uint8_t value)
{
	char tmp[10];
	sprintf(tmp, "0x%02X", value);
	result = tmp;
}

void Converter::to_decimal(std::string &result, uint8_t value)
{
	(void)result;
	(void)value;
}

void Converter::to_binary(std::string &result, uint8_t value)
{
	(void)result;
	(void)value;
}

uint8_t Converter::from_hex(const std::string &value)
{
	(void)value;
	return 0;
}

uint8_t Converter::from_decimal(const std::string &value)
{
	(void)value;
	return 0;
}

uint8_t Converter::from_binary(const std::string &value)
{
	(void)value;
	return 0;
}
