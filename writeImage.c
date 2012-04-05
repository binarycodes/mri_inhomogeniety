/*
 * File:   writeImage.h
 * Author: sayandeep
 *
 * Created on 4 April, 2012, 4:12 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include "config.h"

void writeImage(int **imageMatrix,int y,int x,int flag) {
    char filename[50]="";
    char folder[20]="segmented_source";

    int i,j;
    FILE *img;

    if (mkdir(folder,(S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))!=0 && errno!=EEXIST) {
        printf("cannot create directory: %s -- %s\n",folder,strerror(errno));
        exit(EXIT_FAILURE);
    }

    if(chdir(folder)!=0) {
        printf("cannot create directory: %s -- %s\n",folder,strerror(errno));
        exit(EXIT_FAILURE);
    }

    switch(flag) {
    case 1:
        strcpy(filename,"seg_bck.pgm");
        break;
    case 2:
        strcpy(filename,"seg_csf.pgm");
        break;
    case 3:
        strcpy(filename,"seg_gm.pgm");
        break;
    case 4:
        strcpy(filename,"seg_wm.pgm");
    }

    img=fopen(filename,"wb");
    if (img == NULL) {
        printf("cannot open file: %s -- %s\n",filename,strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(img,"P2\n#created by sdr\n181 217\n255\n");

    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            fprintf(img,"%d\t",imageMatrix[i][j]);
        }
        fprintf(img,"\n");
    }

    if(fclose(img)!=0) {
        printf("%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    };
}

