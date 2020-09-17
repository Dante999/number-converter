#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <stdint.h>
#include <string>
#include <string_view>

class Number {

      private:
	std::string m_hex;
	std::string m_decimal;
	std::string m_ascii;
	uint8_t     m_value;

	void to_hex(uint8_t value);
	void to_ascii(uint8_t value);
	void to_decimal(uint8_t value);

	void from_hex(const std::string &value);
	void from_ascii(const std::string &value);
	void from_decimal(const std::string &value);

      public:
	Number(void);

	void parse(const std::string &input);

	const std::string_view get_hex(void) const;
	const std::string_view get_decimal(void) const;
	const std::string_view get_ascii(void) const;
};

#endif // NUMBER_HPP_INCLUDED
