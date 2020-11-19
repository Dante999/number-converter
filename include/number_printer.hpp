#ifndef NUMBER_PRINTER_HPP
#define NUMBER_PRINTER_HPP

#include "number.hpp"

class NumberPrinter {

      public:
	NumberPrinter() = delete;

	static void print(Number &number);
};

#endif // NUMBER_PRINTER_HPP
