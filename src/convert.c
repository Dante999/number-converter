#include "convert.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h> // sscanf()
#include "ascii_table.h"


#define MAX_LENGTH 10
#define PREFIX_LENGTH 2
#define PREFIX_HEX      "0x"
#define PREFIX_BINARY   "0b"
#define PREFIX_DECIMAL  "0d"


/**
 * this structure is only used in this module to hold relevant information
 * between the method calls
 */
struct data {
	uint8_t value;             // the value as a integer
	char ascii[MAX_LENGTH];    // ascii representation (e.g. "A")
	char dec[MAX_LENGTH];      // decimal representation (e.g. "0d65")
	char binary[MAX_LENGTH];   // binary representation (e.g. "0b1100 0011")
	char hex[MAX_LENGTH];      // hex representation (e.g. "0x0F")
};


/*******************************************************************************
 * checks if the given string starts with the expected prefix
 *
 * @param *s        the complete string
 * @param *prefix   the expected prefix
 *
 * @return true if the prefix matches, otherwise false
 ******************************************************************************/
static bool prefix_matches(const char *s, const char *prefix) {

	if( strncmp(s, prefix, PREFIX_LENGTH) == 0 )
		return true;
	else
		return false;

}


/*******************************************************************************
 * saves the decimal representation of a number to the given struct
 *
 * @param *s   the string with the decimal representation of a number
 * @param *d   pointer to the structure for saving the value
 *
 * @return  0   if success
 *         -1   if the value is out of range
 ******************************************************************************/
static int8_t interpret_decimal(const char *s, struct data *d) {

	int i;

	sscanf(s, "%d", &i);

	if( i < 0 || 255 < i ) {
		d->value = 0;
		printf("Error: Decimal number negative or greater than 255: %s", s);
		return -1;
	}
	else {
		d->value = (uint8_t) i;
		return 0;
	}

}


/*******************************************************************************
 * saves the hex representation of a number to the given struct
 *
 * @param *s   the string with the hex representation of a number
 * @param *d   pointer to the structure for saving the value
 *
 * @return  0   if success
 *         -1   if the value is out of range
 ******************************************************************************/
static int8_t interpret_hex(const char *s, struct data *d) {

	int i;

	sscanf(s, "%X", &i);

	if( i < 0 || 255 < i ) {
		d->value = 0;
		printf("Error: Hex number negative or greater than 255: %s\n", s);
		return -1;
	}
	else {
		d->value = (uint8_t) i;
		return 0;
	}

}


/*******************************************************************************
 * saves the binary representation of a number to the given struct
 *
 * @param *s   the string with the binary representation of a number
 * @param *d   pointer to the structure for saving the value
 *
 * @return  0   if success
 *         -1   if the value is out of range
 ******************************************************************************/
static int8_t interpret_binary(const char *s, struct data *d) {

	uint8_t value = 0;


	uint8_t actual_length   = strlen(s);
	uint8_t expected_length = 8;

	if( actual_length != expected_length ) {
		printf("Error: Binary format has length %i instead of %i!\n", 
				actual_length, expected_length);
		return -1;
	}

	for( uint8_t i=0; i < expected_length; i++ ) {
		
		if( s[i] == '1' )
			value |= (1<< (7-i));

	}

	d->value = value;


	return 0;
}


/*******************************************************************************
 * prints the content of the struct to the terminal
 *
 * @param   *d   pointer to the data structure
 *
 * @return  none
 ******************************************************************************/
static void print_result(struct data *d) {

	char *ascii = d->ascii;
	char *dec = d->dec;
	char *hex = d->hex;
	char *bin = d->binary;

	printf("--------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s\n", "ASCII", "DEC", "HEX", "BIN");
	printf("%-10s %-10s %-10s %-10s\n", ascii, dec, hex, bin);
	printf("--------------------------------------------\n\n");

}


/*******************************************************************************
 * checks if the bit is set
 *
 * @param   byte   a byte
 * @param   bit    the bit number to check
 *
 * @return  '1' if the bit in the byte was set, otherwise 
 *          '0' if the bit was not set
 ******************************************************************************/
static char get_bit(char byte, uint8_t bit) {
	return (byte & (1<<bit) ? '1' : '0');
}


/*******************************************************************************
 * formats the value to the different number representations
 *
 * @param   *d   pointer to the data structure
 *
 * @return  none
 ******************************************************************************/
static void format_result(struct data *d) {

	uint8_t value = d->value;

	sprintf(d->dec, "0d%d", value); // decimal
	sprintf(d->hex, "0x%02X", value); // hex
	sprintf(d->binary, "%c%c%c%c %c%c%c%c", 
			get_bit(value, 7), get_bit(value, 6),
			get_bit(value, 5), get_bit(value, 4),
			get_bit(value, 3), get_bit(value, 2),
			get_bit(value, 1), get_bit(value, 0)
	       );
	
	sprintf(d->ascii, "%s", value < 128 ? ascii_table[value] : "undefined");
	
}


/*******************************************************************************
 * converts the given string into the different number representations and 
 * prints them on the command line
 *
 * @param   *s   the string for converting
 *
 * @return  none
 ******************************************************************************/
void convert(const char *s) {

	struct data d;

	int8_t result = -1;

	const char *v = s+PREFIX_LENGTH; // skip the prefix

	if( prefix_matches(s, PREFIX_DECIMAL) )
		result = interpret_decimal(v, &d);
	else if( prefix_matches(s, PREFIX_HEX) )
		result = interpret_hex(v, &d);
	else if( prefix_matches(s, PREFIX_BINARY) ) 
		result = interpret_binary(v, &d);
	else
		printf("No expected prefix found!\n");


	if(result == 0) {
		format_result(&d);
		print_result(&d);
	}
	else {
		printf("Something went wrong!\n");
	}

}







