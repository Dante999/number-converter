#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <stdint.h>
#include <string>

class Converter {

      public:
	static const int         PREFIX_LENGTH;
	static const std::string PREFIX_HEX;
	static const std::string PREFIX_BINARY;
	static const std::string PREFIX_DECIMAL;

      private:
	static uint8_t from_hex(const std::string &value);
	static uint8_t from_decimal(const std::string &value);
	static uint8_t from_binary(const std::string &value);
	static uint8_t from_ascii(const std::string &value);
	
      public:
	Converter() = delete;

	static void to_hex(std::string &result, uint8_t value);
	static void to_decimal(std::string &result, uint8_t value);
	static void to_binary(std::string &result, uint8_t value);
	static void to_ascii(std::string &result, uint8_t value);

	static uint8_t parse(const std::string &input);
};

#endif // CONVERTER_HPP
