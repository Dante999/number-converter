#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include <string.h>

// 0b11001100\n\0
#define MAX_INPUT   12

void remove_newline(char *input) {
    char *newline_char = strchr(input, '\n');

    if( newline_char != NULL ) {
        *newline_char = '\0';
    }
}

void clear_buffer() {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{

    printf("########################################################\n");
    printf("# Converter tool made by Dante999                      #\n");
    printf("########################################################\n");
    printf("\n");
    printf("usage: 0d127 0xAB 0b00001111\n");
    printf("--------------------------------------------------------\n");

    char input[MAX_INPUT];

    while( strcmp(input, "exit") != 0) {


        printf("Enter your value: ");
        fgets(input, sizeof(input), stdin);
        clear_buffer();

        remove_newline(input);
        convert(input);
    }

    return 0;
}
