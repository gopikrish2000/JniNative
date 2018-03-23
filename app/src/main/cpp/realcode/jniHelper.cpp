//
// Created by Gopi on 22/03/18.
//

#include <iostream>
#include "headers/jniHelper.h"

using namespace std;


double *getDoublesGreaterThanNumber(double *inputAry, int length, double numb, int *size) {
    int i, j=0;
    double *result = inputAry;
    for (i = 0; i < length; i++) {
        if (inputAry[i] > numb) {
            *(result+j) = inputAry[i];
            j++;
        }
    }
    *size = j;
    for(j; j<length; j++){
        *(result + j) = -100;  // make end elements  -100
    }
    return result;
}