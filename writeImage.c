/*
 * File:   writeImage.h
 * Author: sayandeep
 *
 * Created on 4 April, 2012, 4:12 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

#include "config.h"

void writeImage(int **imageMatrix,int y,int x,int flag)
{
    char filename[50];
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

    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            fprintf(img,"%d\t",imageMatrix[i][j]);
        }
        fprintf(img,"\n");
    }
    fclose(img);
    /*for(i=0;i<YAXIS;i++)
      {
      for(j=0;j<XAXIS;j++)
      {
      printf("\t%d",imageMatrix[i][j]);
      }
      }*/
}

