#include "convert.hpp"

#include <iostream>
#include <string>

/*******************************************************************************
 * the main function
 *
 * @param   none
 *
 * @return  0 if the program is finished
 ******************************************************************************/
int main()
{

	std::cout << "########################################################\n";
	std::cout << "# Converter tool made by Dante999                      #\n";
	std::cout << "########################################################\n";
	std::cout << "\n";
	std::cout << "usage: 0d127 0xAB 0b00001111\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\n\n";

	std::string user_input = "";


	while (user_input.compare("exit") != 0) {

		std::cout << "Enter your value: ";
		std::cin >> user_input;

		convert(user_input.c_str());

	}

	return 0;
}
