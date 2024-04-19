#include "ASCII.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shift_digits(int input_integer) {
    // Convert the integer to a string
    char input_str[20];
    sprintf(input_str, "%d", input_integer);

    // Allocate memory for the result string
    char* result_str = malloc(3 * strlen(input_str));

    // Shift each digit by +48 and join them with spaces
    int index = 0;
    for (int i = 0; i < strlen(input_str); i++) {
        int shifted_digit = input_str[i];
        index += sprintf(result_str + index, "%d ", shifted_digit);
    }

    // Remove the trailing space and add the null terminator
    result_str[index - 1] = '\0';

    return result_str;
}
