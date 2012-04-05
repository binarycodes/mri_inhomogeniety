/* 
 * File:   imageSegment.H
 * Author: sayandeep
 *
 * Created on 4 April, 2012, 3:20 PM
 */

#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>

#include "config.h"
#include "writeImage.h"

void imageSegment(int **imageMatrix,int y,int x)
{
    int **imageMatrix_bck,**imageMatrix_csf,**imageMatrix_gm,**imageMatrix_wm;
    int i,j,flag=0;
    
    imageMatrix_bck=(int **)malloc(YAXIS * sizeof(int *));
    for(i=0;i<YAXIS;i++)
        imageMatrix_bck[i]=(int *)malloc(XAXIS * sizeof(int *));

    imageMatrix_csf=(int **)malloc(YAXIS * sizeof(int *));
    for(i=0;i<YAXIS;i++)
        imageMatrix_csf[i]=(int *)malloc(XAXIS * sizeof(int *));

    imageMatrix_gm=(int **)malloc(YAXIS * sizeof(int *));
    for(i=0;i<YAXIS;i++)
        imageMatrix_gm[i]=(int *)malloc(XAXIS * sizeof(int *));

    imageMatrix_wm=(int **)malloc(YAXIS * sizeof(int *));
    for(i=0;i<YAXIS;i++)
        imageMatrix_wm[i]=(int *)malloc(XAXIS * sizeof(int *));

    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            imageMatrix_bck[i][j]=imageMatrix[i][j];
            imageMatrix_csf[i][j]=imageMatrix[i][j];
            imageMatrix_gm[i][j]=imageMatrix[i][j];
            imageMatrix_wm[i][j]=imageMatrix[i][j];
        }
    }
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            if(imageMatrix_bck[i][j]>=22)
            {
                imageMatrix_bck[i][j]=0;
            }
            if(imageMatrix_csf[i][j]>22 && imageMatrix_csf[i][j]<=75)
            {
                imageMatrix_csf[i][j]=imageMatrix_csf[i][j];
            }
            else{
                imageMatrix_csf[i][j]=0;
            }
            if(imageMatrix_gm[i][j]>75 && imageMatrix_gm[i][j]<=131)
            {
                imageMatrix_gm[i][j]=imageMatrix_gm[i][j];
            }
            else{
                imageMatrix_gm[i][j]=0;
            }
            if(imageMatrix_wm[i][j]>131 && imageMatrix_gm[i][j]<=255)
            {
                imageMatrix_wm[i][j]=imageMatrix_wm[i][j];
            }
            else{
                imageMatrix_wm[i][j]=0;
            }
        }
    }
    /*for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            printf("\t%d",imageMatrix_csf[i][j]);
        }
    }*/
    printf("WHOOO");
    flag=2;
    writeImage(imageMatrix_csf,YAXIS,XAXIS,flag);

}

