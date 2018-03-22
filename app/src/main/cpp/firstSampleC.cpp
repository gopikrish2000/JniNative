//
// Created by Gopi on 21/03/18.
//


#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LENGTH 10  // constant

const int WIDTH1 = 20; // constant
static int firstStaticVar = 222;

int ary1[] = {2, 3, 5, 6};

#define MAX(x,y) ((x) > (y) ? (x) : (y))


void printa() {
    printf("aaa");
    printf("Storage size for int : %d \n", sizeof(int) + " first static var " + firstStaticVar);
    if (firstStaticVar > 20) {

    } else if (firstStaticVar > 40) {

    }
    for (int i = 0; i < firstStaticVar; ++i) {
        //
    }
//    return "aaa";
}

int abc() {
    return 2;
}

int *returnAry() {
    static int ary[4] = {2, 3, 5,
                         6};  // To return local array it has to be static or it should be instance variable or it can be malloced.
    return ary;
}

int firstElementInArray(int ary[]) {
    return ary[0];
}

void pointerToPointer() {
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    /* take the address of var */
    ptr = &var;

    /* take the address of ptr using address of operator & */
    pptr = &ptr;

    /* take the value using pptr */
    printf("Value of var = %d\n", var);
    printf("Value available at *ptr = %d\n", *ptr);
    printf("Value available at **pptr = %d\n", **pptr);

}

void printStringAry() {
    char *names[] = {
            "Zara Ali",
            "Hina Ali",
            "Nuha Ali",
            "Sara Ali"
    };
    char firstString[] = "firstStr";
    char secondString[] = "secondStr";

    int i = 0;

    for (i = 0; i < 4; i++) {
        printf("Value of names[%d] = %s\n", i, names[i]);
    }
    /*printf(firstString);
    printf(" \n");*/
    strcat(firstString, secondString);
    printf("concatinated %s",firstString);
    printf("stringlength %d", strlen(firstString));
    strstr(firstString, secondString); //Returns a pointer to the first occurrence of string s2 in string s1.
    strchr(firstString, 'i'); //Returns a pointer to the first occurrence of character ch in string s1.
}

double average(int num, ...) {

    va_list valist;
    double sum = 0.0;
    int i;

    /* initialize valist for num number of arguments */
    va_start(valist, num);

    /* access all the arguments assigned to valist */
    for (i = 0; i < num; i++) {
        sum += va_arg(valist, int);
    }

    /* clean memory reserved for valist */
    va_end(valist);

    return sum / num;
}



int main() {
    int *ptr = NULL;
    if (!ptr) {
        printf("pointer is not null");
    }
    const int WIDTH = 20; // constant
    printa();
    int *ary = returnAry();
    int i;
    for (i = 0; i < 4; ++i) {

        //int res = *(ary + i);
        int res = ary[i];
        printf(" i val is %d \n", res);
    }

    printf("Max between 20 and 10 is %d\n", MAX(10, 20));
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
    //printf(" abc val is %d", abc());
    return 0;
}