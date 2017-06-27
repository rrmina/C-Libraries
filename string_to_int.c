#include <stdio.h>
#include <string.h> /* from string import strlen */
#include <math.h>   /* from math import pow */
#include <stdlib.h> /* from stdlib import calloc */

int strtoint(char *num);
char** split(char *str, char *delim);
void strmk(char *str_p, char *str, int len);

/*
 *    String to Int function
 */
int strtoint(char *num) {
    // Get string length
    int len = strlen(num);

    // Get sign of number
    int sign = 0;
    if (num[0] == '-')
        sign = 1;

    // Get value starting from ones digit
    int count = len - 1,
        val = 0,
        mult = 1;
    while (count > sign - 1) {
        val = val + (num[count] - '0') * mult;
        count--;
        mult *= 10;
    }

    return val * pow(-1, sign);
}

/*
 *  String to array of Int
 */
char** split(char *str, char *delim) {
    char **ret = (char **)malloc(1);

    char *token;
    token = strtok(str, delim);

    int count = 0;
    while (token != NULL) {
        strmk(*(ret + count), token, strlen(token));
        token = strtok(NULL, delim);
        count++;
    }

    return ret;
}

/*
 *  String allocation
 */
void strmk(char *str_p, char *str, int len) {
    printf("%s\n", str);
    str_p = (char *)calloc(len + 1, sizeof(char));
    strcpy(str_p, str);
    printf("%s\n", str_p);
}

int main (void) {
    // strtoint
    char try[5] = "-10";
    int hello;
    hello = strtoint(try);
    printf("%d\n", hello);

    // strmk
    char *yeyeye;
    char hellos[4] = "new";
    strmk(yeyeye, hellos, strlen(hellos));

    // split
    char yeye[20] = "he he he he ha";
    char delim[2] = " ";
    char **fofo;
    fofo = split(yeye, delim);

    printf("%s\n", *(fofo + 1));
/*
    int counter = 0;
    while (counter < 5) {
        printf("%s\n", *(fofo + counter));
        counter++;
    }
*/

    return 0;
}