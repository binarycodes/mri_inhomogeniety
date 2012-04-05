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
    int i, j;
    int N, M, Q;
    int **imageMatrix;
    FILE *fp;

    readImage(argv[1], &imageMatrix, &M, &N, &Q);
    imageSegment(imageMatrix, XAXIS, YAXIS);

    return 0;
}
