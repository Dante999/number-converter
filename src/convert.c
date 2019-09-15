#include "convert.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ascii_table.h"


#define MAX_LENGTH      10

#define PREFIX_LENGTH   2
#define PREFIX_HEX      "0x"
#define PREFIX_BINARY   "0b"
#define PREFIX_DECIMAL  "0d"

static bool prefix_matches(const char *actual, const char *expected);
static char read_bit(char byte, uint8_t bit_number);

static void convert_print(char number);

static uint8_t read_from_input(const char *prefix, const char *value);
static uint8_t read_from_decimal(const char *input);
static uint8_t read_from_hex(const char *input);
static uint8_t read_from_binary(const char *input);

static void write_as_decimal(char *storage, uint8_t value);
static void write_as_hex(char *storage, uint8_t value);
static void write_as_ascii(char *storage, uint8_t value);
static void write_as_binary(char *storage, uint8_t value);


void convert(const char *input) {

    char prefix[3];
    char value[MAX_LENGTH];
    uint8_t number = 255;

    strncpy(prefix, input, PREFIX_LENGTH);
    strncpy(value, input+PREFIX_LENGTH, sizeof(input-PREFIX_LENGTH));

    number = read_from_input(prefix, value);
    convert_print(number);
}


static bool prefix_matches(const char *actual, const char *expected) {
    if( strncmp(actual, expected, PREFIX_LENGTH) == 0 ) {
        return true;
    }
    else {
        return false;
    }
}


static uint8_t read_from_input(const char *prefix, const char *value) {

    uint8_t result = 0;

    if( prefix_matches(prefix, PREFIX_DECIMAL) ) {
        result = read_from_decimal(value);
    }
    else if( prefix_matches(prefix, PREFIX_HEX) ) {
        result = read_from_hex(value);
    }
    else if( prefix_matches(prefix, PREFIX_BINARY) ) {
        result = read_from_binary(value);
    }

    return result;
}


static void convert_print(char number) {
    char ascii[MAX_LENGTH];
    char dez[MAX_LENGTH];
    char hex[MAX_LENGTH];
    char bin[MAX_LENGTH];

    write_as_ascii(ascii, number);
    write_as_decimal(dez, number);
    write_as_hex(hex, number);
    write_as_binary(bin, number);

    printf("--------------------------------------------\n");
    printf("%-10s %-10s %-10s %-10s\n", "ASCII", "DEC", "HEX", "BIN");
    printf("%-10s %-10s %-10s %-10s\n", ascii, dez, hex, bin);
    printf("--------------------------------------------\n\n");
}



static uint8_t read_from_decimal(const char *input) {
    int i;

    sscanf(input, "%d", &i);

    if( i > 255) {
        printf("NUMER %s TOO LARGE!!", input);
        return 0;
    }
    else {
        return (char) i;
    }

}

static uint8_t read_from_hex(const char *input) {
    int i;

    sscanf(input, "%X", &i);

    if( i > 255) {
        printf("NUMER %s TOO LARGE!!", input);
        return 0;
    }
    else {
        return (char) i;
    }
}

static uint8_t read_from_binary(const char *input) {

    uint8_t result = 0;

    for( uint8_t i=0; i < 8; i++) {

        if( strncmp(input+i, "1", 1) == 0) {
            printf("bit %d is 1 \n", i);
            result |= ( 1<<(7-i) );
        }
        else if( strncmp(input+i, "0", 1) == 0) {
            printf("bit %d is 0 \n", i);
        }
        else {
            printf("bit %d is unkown \n", i);
        }

    }

    return result;
}

static void write_as_decimal(char *storage, uint8_t value) {
    sprintf(storage, "0d%d", value);
}

static void write_as_hex(char *storage, uint8_t value) {
    sprintf(storage, "0x%X", value);
}

static void write_as_ascii(char *storage, uint8_t value) {

   if( 0 < value && value < 128) {
        sprintf(storage, "%s", ascii_table[(int)value]);
   }
   else {
        sprintf(storage, "%s", "undefined");
   }

}

static void write_as_binary(char *storage, uint8_t value) {
    sprintf(storage, "%c%c%c%c %c%c%c%c", read_bit(value, 7),
            read_bit(value, 6), read_bit(value, 5),
            read_bit(value, 4), read_bit(value, 3),
            read_bit(value, 2), read_bit(value, 1),
            read_bit(value, 0));
}

static char read_bit(char byte, uint8_t bit_number ) {

    if( byte & (1<<bit_number) ) {
        return '1';
    }
    else {
        return '0';
    }
}


