#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int a, b, max_number, mod, counter = 1;

int main(void) {
m1:
    printf("Enter a(0-100000), b(0-32): ");
    int n = scanf("%d, %d", &a, &b);
    if (n < 2) {
        printf("You must enter 2 numbers!\n\n");
        goto m1;
    }
    int a_copy = a;
    if (a > 100000 || a < 0) {
        printf("a must be in [0; 100000]\n\n");
        goto m1;
    }
    if (b > 32 || b < 0) {
        printf("b must be in [0; 32]\n\n");
        goto m1;
    }

m2:
    a_copy /= b;
    if (a_copy != 0) {
        max_number += 1;
        goto m2;
    }
    a_copy = a;
    mod = a_copy % b;
m3:
    if (counter <= max_number) {
        a_copy /= b;
        mod = a_copy % b;
        counter += 1;
        goto m3;
    }

    printf("%d ", mod);
    max_number -= 1;
    counter = 1;
    a_copy = a;
    mod = a_copy % b;
    if (max_number >= 0) {
        goto m3;
    }

    return 0;
}