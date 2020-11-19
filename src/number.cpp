#include "number.hpp"

#include <iostream>

#include "converter.hpp"

Number::Number(void) : m_value(0xFF)
{
	// nothing else to do
}

void Number::parse(const std::string &input)
{
	m_value = Converter::parse(input);
	Converter::to_decimal(m_decimal, m_value);
	Converter::to_hex(m_hex, m_value);
	Converter::to_binary(m_binary, m_value);
}

const std::string& Number::get_hex() const
{
	return m_hex;
}

const std::string& Number::get_decimal() const
{
	return m_decimal;
}

const std::string& Number::get_ascii() const
{
	return m_ascii;
}

const std::string& Number::get_binary() const
{
	return m_binary;
}
