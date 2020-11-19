#include "number_printer.hpp"

#include <iostream>

void NumberPrinter::print(Number &number)
{
	const char *ascii = "";
	const char *dec   = number.get_decimal().c_str();
	const char *hex   = number.get_hex().c_str();
	const char *bin   = number.get_binary().c_str();

	printf("--------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s\n", "ASCII", "DEC", "HEX", "BIN");
	printf("%-10s %-10s %-10s %-10s\n", ascii, dec, hex, bin);
	printf("--------------------------------------------\n\n");
}
