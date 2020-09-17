#include "number.hpp"

Number::Number() {}

void Number::parse(const std::string &input)
{
	std::string prefix = input.substr(0, 2);
}

void Number::to_hex(uint8_t value) {}

void Number::to_ascii(uint8_t value) {}

void Number::to_decimal(uint8_t value) {}

void Number::from_hex(const std::string &value) {}

void Number::from_ascii(const std::string &value) {}

void Number::from_decimal(const std::string &value) {}

const std::string_view Number::get_hex() const
{
	return m_hex;
}

const std::string_view Number::get_decimal() const
{
	return m_decimal;
}

const std::string_view Number::get_ascii() const
{
	return m_ascii;
}
