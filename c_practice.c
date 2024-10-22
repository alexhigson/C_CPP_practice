#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validate_phone(const char* phone_number) {

    if (phone_number == NULL || strlen(phone_number) < 12 || strlen(phone_number) > 13 || phone_number[0] != '+' || phone_number[1] != '4' || phone_number[2] != '4') {
        return 0;
    }

    while (*phone_number != '\0') {
        if (!isdigit(*phone_number) && *phone_number != '+') {
        return 0;
        }
        phone_number++;
    }

    return 1;
}  

int main() {

    char phone_number[] = "+447012345678";
    if (validate_phone(phone_number)) {
        printf("Phone number is valid.\n");
    } else {
        printf("Phone number is invalid.\n");
    }

}
