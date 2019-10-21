#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include <string.h>

// the maximum length of user input from the terminal (0b11001100\n\0)
#define MAX_INPUT   12



/*******************************************************************************
 * removes the newline character from the given string
 *
 * @param   none
 *
 * @return  none
 ******************************************************************************/
static void remove_newline(char *s) {

	char *c = strchr(s, '\n');

	if( c != NULL ) {
		*c = '\0';
	}
}


/*******************************************************************************
 * clears the stdin buffer
 *
 * @param   none
 *
 * @return  none
 ******************************************************************************/
static void clear_buffer() {
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}


/*******************************************************************************
 * the main function
 *
 * @param   none
 *
 * @return  0 if the program is finished
 ******************************************************************************/
int main() {

	printf("########################################################\n");
	printf("# Converter tool made by Dante999                      #\n");
	printf("########################################################\n");
	printf("\n");
	printf("usage: 0d127 0xAB 0b00001111\n");
	printf("--------------------------------------------------------\n");
	printf("\n\n");

	char input[MAX_INPUT];

	while( strcmp(input, "exit") != 0) {

		printf("Enter your value: ");

		if( fgets(input, MAX_INPUT, stdin) != NULL) {
			remove_newline(input);
			convert(input);
		}
		else {
			printf("Error during reading from stdin");
		}


		//clear_buffer();
	}

	return 0;
}



