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
#include "imageSegment.h"
#include "writeImage.h"

static const int itr=4;

static void dynamic_array(int ****array, int y, int x) {
    int i=0,j=0;

    *array = (int ***) malloc(itr * sizeof(int *));

    if (*array == NULL) {
        printf("cannot allocate memory -- %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    for(i=0;i<itr;i++) {
        (*array)[i]=(int **)malloc(y * sizeof(int));
        if ((*array)[i] == NULL) {
            printf("cannot allocate memory -- %s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }

        for(j=0;j<y;j++) {
            (*array)[i][j]=(int *)malloc(x * sizeof(int));
            if ((*array)[i][j] == NULL) {
                printf("cannot allocate memory -- %s\n",strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
    }
}

void imageSegment(int **imageMatrix,int y,int x) {
    int ***imageMatrix_seg;
    int i=0,j=0,k=0;

    dynamic_array(&imageMatrix_seg,y,x);

    for(k=0;k<itr;k++) {
        for(i=0;i<y;i++) {
            for(j=0;j<x;j++) {
                imageMatrix_seg[k][i][j]=imageMatrix[i][j];
            }
        }
    }

    for(k=0;k<4;k++)
    {
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                switch(k) {
                case 0:
                    if(imageMatrix_seg[k][i][j]>=22)
                        imageMatrix_seg[k][i][j]=0;
                    break;
                case 1:
                    if(imageMatrix_seg[k][i][j]<=22 || imageMatrix_seg[k][i][j]>75)
                        imageMatrix_seg[k][i][j]=0;
                    break;
                case 2:
                    if(imageMatrix_seg[k][i][j]<=75 || imageMatrix_seg[k][i][j]>131)
                        imageMatrix_seg[k][i][j]=0;
                    break;
                case 3:
                    if(imageMatrix_seg[k][i][j]<=131 || imageMatrix_seg[k][i][j]>255)
                        imageMatrix_seg[k][i][j]=0;
                    break;
                }
            }
        }
    }

    writeImage(imageMatrix_seg,YAXIS,XAXIS,itr);


	/* all that is allocated must be de-allocated */
    for (i=0;i<itr;i++) {
        for(j=0;j<y;j++) {
            free(imageMatrix_seg[i][j]);
        }
        free(imageMatrix_seg[i]);
    }
    free(imageMatrix_seg);

}
