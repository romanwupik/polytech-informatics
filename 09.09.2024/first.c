#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int get_number(int num, int notation, int cnt) {
    int counter = 1, mod = num % notation;
m1:
    if (counter <= cnt) {
        num /= notation;
        mod = num % notation;
        counter += 1;
        goto m1;
    }
    if (num != 0) {
        return mod;
    }
}

int get_cnt(int num, int notation) {
    int counter = 0;
m2:
    num /= notation;
    if (num != 0) {
        counter += 1;
        goto m2;
    }
    return counter;
}

void print_number(int num, int notation) {
    int max_cnt = get_cnt(num, notation);
m3:
    if (max_cnt >= 0) {
        printf("%d ", get_number(num, notation, max_cnt));
        max_cnt -= 1;
        goto m3;
    }
}

int a, b;

int main(void) {
m4:
    printf("Enter a(0-100000), b(0-32): ");
    int n = scanf("%d, %d", &a, &b);
    if (n < 2) {
        printf("You must enter 2 numbers!\n\n");
        goto m4;
    }

    if (a > 100000 || a < 0) {
        printf("a must be in [0; 100000]\n\n");
        goto m4;
    }
    if (b > 32 || b < 0) {
        printf("b must be in [0; 32]\n\n");
        goto m4;
    }

    print_number(a, b);
    return 0;
}