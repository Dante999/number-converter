#include "convert.hpp"

#include <iostream>
#include <string>

#include "number.hpp"
#include "number_printer.hpp"

/*******************************************************************************
 * the main function
 *
 * @param   none
 *
 * @return  0 if the program is finished
 ******************************************************************************/
int main()
{

	std::cout << "######################################################\n";
	std::cout << "# Converter tool made by Dante999                    #\n";
	std::cout << "######################################################\n";
	std::cout << "\n";
	std::cout << "usage: 0d127 0xAB 0b00001111\n";
	std::cout << "------------------------------------------------------\n";
	std::cout << "\n\n";

	std::string user_input = "";

	auto number = Number();

	while (user_input.compare("exit") != 0) {

		std::cout << "Enter your value: ";
		std::cin >> user_input;

		try {
			number.parse(user_input);
			NumberPrinter::print(number);
		} catch (const char *msg) {
			std::cout << "->faild to parse input: " << msg << '\n';
			std::cout << '\n';
		}
	}

	return 0;
}
