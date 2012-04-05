/* 
 * File:   writeImage.h
 * Author: sayandeep
 *
 * Created on 4 April, 2012, 4:12 PM
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <cmath>

#include "config.h"

void writeImage(int **imageMatrix,int y,int x,int flag)
{
    char *filename;
    char folder[20]="segmented_source";
    
    int i,j,counter=0;
    FILE *img;
    mkdir(folder,S_IRWXU);
    chdir(folder);
    
    if(flag==1)
        strcpy(filename,"seg_bck.pgm");
    if(flag==2)
        strcpy(filename,"seg_csf.pgm");
    if(flag==3)
        strcpy(filename,"seg_gm.pgm");
    if(flag==4)
        strcpy(filename,"seg_wm.pgm");

    img=fopen(filename,"wb");

    fprintf(img,"P2\n#created by sdr\n181 217\n255\n");

    imageMatrix=(int **)malloc(YAXIS * sizeof(int *));
    for(i=0;i<YAXIS;i++)
        imageMatrix[i]=(int *)malloc(XAXIS * sizeof(int *));
    /*for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            fprintf(img,"%d\t",imageMatrix[i][j]);
            //counter=counter+181;
        }
        fprintf(img,"\n");
    }*/
    fclose(img);
    for(i=0;i<YAXIS;i++)
    {
        for(j=0;j<XAXIS;j++)
        {
            printf("\t%d",imageMatrix[i][j]);
        }
    }
}

