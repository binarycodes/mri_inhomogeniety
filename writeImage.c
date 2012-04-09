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
#include "writeImage.h"

void writeImage(int ***imageMatrix,int y,int x, int itr) {
    char folder[20]="segmented_source";
    char filenames[4][20]={"seg_bck.pgm","seg_csf.pgm","seg_gm.pgm","seg_wm.pgm"};
    int i=0,j=0,k=0;
    FILE *img;



    if(chdir(folder)!=0) {
        if (mkdir(folder,(S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))!=0 && errno!=EEXIST) {
            printf("cannot create directory: %s -- %s\n",folder,strerror(errno));
            exit(EXIT_FAILURE);
        }
        if(chdir(folder)!=0) {
            printf("cannot enter directory: %s -- %s\n",folder,strerror(errno));
            exit(EXIT_FAILURE);
        }

    }

    for (k=0;k<itr;k++) {

        img=fopen(filenames[k],"wb");
        if (img == NULL) {
            printf("cannot open file: %s -- %s\n",filenames[k],strerror(errno));
            exit(EXIT_FAILURE);
        }

        fprintf(img,"P2\n#created by sdr\n181 217\n255\n");

        for(i=0;i<y;i++) {
            for(j=0;j<x;j++) {
                fprintf(img,"%d\t",imageMatrix[k][i][j]);
            }
            fprintf(img,"\n");
        }

        if(fclose(img)!=0) {
            printf("%s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

}

