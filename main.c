/*
 * File:   main.cpp
 * Author: sayandeep
 *
 * Created on 2 April, 2012, 1:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "config.h"
#include "imageSegment.h"
#include "readImage.h"

int main(int argc, char *argv[]) {
    int i=0, j=0;
    int N=0, M=0, Q=0;
    int **imageMatrix=NULL;
    FILE *fp=NULL;

    readImage(argv[1], &imageMatrix, &M, &N, &Q);
    imageSegment(imageMatrix, YAXIS, XAXIS);

    for (i=0;i<YAXIS;i++) {
        free(imageMatrix[i]);
    }
    free(imageMatrix);

    return 0;
}
