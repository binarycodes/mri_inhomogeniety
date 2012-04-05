/*
 * File:   imageSegment.H
 * Author: sayandeep
 *
 * Created on 4 April, 2012, 3:20 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "config.h"
#include "writeImage.h"

void dynamic_array(int ***array, int y, int x) {
    int i=0;

    *array = (int **) malloc(y * sizeof(int *));

    if (*array == NULL) {
        printf("cannot allocate memory -- %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    for(i=0;i<y;i++) {
        (*array)[i]=(int *)malloc(x * sizeof(int));
        if ((*array)[i] == NULL) {
            printf("cannot allocate memory -- %s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}


void imageSegment(int **imageMatrix,int y,int x) {
    int **imageMatrix_bck;
    int **imageMatrix_csf;
    int **imageMatrix_gm;
    int **imageMatrix_wm;
    int i=0,j=0,flag=0;

    dynamic_array(&imageMatrix_bck,y,x);
    dynamic_array(&imageMatrix_csf,y,x);
    dynamic_array(&imageMatrix_gm,y,x);
    dynamic_array(&imageMatrix_wm,y,x);


    for(i=0;i<y;i++) {
        for(j=0;j<x;j++) {
            imageMatrix_bck[i][j]=imageMatrix[i][j];
            imageMatrix_csf[i][j]=imageMatrix[i][j];
            imageMatrix_gm[i][j]=imageMatrix[i][j];
            imageMatrix_wm[i][j]=imageMatrix[i][j];
        }
    }


    for(i=0;i<y;i++) {
        for(j=0;j<x;j++) {
            if(imageMatrix_bck[i][j]>=22) {
                imageMatrix_bck[i][j]=0;
            }

            if(imageMatrix_csf[i][j]<=22 || imageMatrix_csf[i][j]>75) {
                imageMatrix_csf[i][j]=0;
            }

            if(imageMatrix_gm[i][j]<=75 && imageMatrix_gm[i][j]>131) {
                imageMatrix_gm[i][j]=0;
            }

            if(imageMatrix_wm[i][j]<=131 && imageMatrix_gm[i][j]>255) {
                imageMatrix_wm[i][j]=0;
            }
        }
    }

    flag=2;
    writeImage(imageMatrix_csf,YAXIS,XAXIS,flag);

    for(i=0;i<YAXIS;i++) {
        free(imageMatrix_bck[i]);
        free(imageMatrix_csf[i]);
        free(imageMatrix_gm[i]);
        free(imageMatrix_wm[i]);
    }
    free(imageMatrix_bck);
    free(imageMatrix_csf);
    free(imageMatrix_gm);
    free(imageMatrix_wm);
}

