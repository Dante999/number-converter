#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <stdint.h>
#include <string>
#include <string_view>

class Number {

      private:
	std::string m_hex;
	std::string m_dec;
	std::string m_ascii;
	uint8_t     m_value;

	void to_hex(uint8_t value);
	void to_ascii(uint8_t value);
	void to_decimal(uint8_t value);

	void from_hex(const std::string &value);
	void from_ascii(const std::string &value);
	void from_decimal(const std::string &value);

      public:
	Number(const std::string &input);
	void set_value(const std::string &input);

	const std::string_view get_hex(void) const;
	const std::string_view get_decimal(void) const;
	const std::string_view get_ascii(void) const;
};

void Number::to_hex(uint8_t value) {}

void Number::to_ascii(uint8_t value) {}

void Number::to_decimal(uint8_t value) {}

void Number::from_hex(const std::string &value) {}

void Number::from_ascii(const std::string &value) {}

void Number::from_decimal(const std::string &value) {}

const std::string_view Number::get_hex() const {}

const std::string_view Number::get_decimal() const {}

const std::string_view Number::get_ascii() const {}

#endif // NUMBER_HPP_INCLUDED
