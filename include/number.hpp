#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <stdint.h>
#include <string>
#include <string_view>

//#define MAX_LENGTH 10
//#define PREFIX_LENGTH 2
//#define PREFIX_HEX "0x"
//#define PREFIX_BINARY "0b"
//#define PREFIX_DECIMAL "0d"

class Number {

      private:
	std::string m_hex;
	std::string m_decimal;
	std::string m_ascii;
	std::string m_binary;
	uint8_t     m_value;

      public:
	Number(void);

	void parse(const std::string &input);

	const std::string& get_hex(void) const;
	const std::string& get_decimal(void) const;
	const std::string& get_ascii(void) const;
	const std::string& get_binary(void) const;
};

#endif // NUMBER_HPP_INCLUDED
