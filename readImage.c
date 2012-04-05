#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readImage(char fname[80], int ***imageMatrix, int *m, int *n, int *max) {
    /*	fname[80]	- image file name
     ***imageMatrix	- address of the 2D array to contain the gray-level values
     *m	- to contain the image width (column no)
     *n	- to contain the image height (row no)
     *max	- to contain the maximum graylevel of the image
     */
    int i, j;
    FILE *imageFile; // the file descriptor to handle the image file
    char oneLine[80]; // to read each line of the imageFile, one at a time
    char str[80];
    int pixVal; // pixel value
    int row, col;

    imageFile = fopen(fname, "r"); // the image file is opened in Read mode

    if (imageFile == NULL) {
        printf("Can't open image file: %s\n", fname);
        exit(0);
    }


    /*	Reading the first line of the gray image, i.e. the Magic number: P2 or, P5	*/
    fgets(oneLine, 80, imageFile);
    while (oneLine[0] == '#' || oneLine[0] == '\n')
        /* while the line is a comment(comment starts with a # character)
                or, its only a newline character, read the next line	*/
        fgets(oneLine, 80, imageFile);
    if (oneLine[0] != 'P' || (oneLine[1] != '2' && oneLine[1] != '5'))
        /* if the magic number is not P2 or, P5, the image is not a PGM image	*/ {
        printf("Image file %s is not a pgm image\n", fname);
        exit(0);
    }



    /*	Reading the second line of the image, i.e the image width(m) and image height(n) */
    /*	Picture is of dimention nXm	*/
    fgets(oneLine, 80, imageFile);
    while (oneLine[0] == '#' || oneLine[0] == '\n')
        /* while the line is a comment(comment starts with a # character)
                or, its only a newline character, read the next line	*/
        fgets(oneLine, 80, imageFile);



    /*	Reading the image width in variable m	*/
    i = j = 0;
    while (oneLine[i] != ' ')
        str[j++] = oneLine[i++];
    str[j] = '\0';
    *m = atoi(str);


    /*	Reading the image height in variable n	*/
    j = 0;
    while (oneLine[i] != '\n')
        str[j++] = oneLine[i++];
    str[j] = '\0';
    *n = atoi(str);


    /*	Reading the third line of the gray image, i.e. the maximum number of gray level, say 255	*/
    fgets(oneLine, 80, imageFile);
    *max = atoi(oneLine);
    printf("Image file name: %s\n", fname);
    printf("Width=%d\nHeight=%d\nMaxGrayLevel=%d\n", *m, *n, *max);



    *imageMatrix = (int**) malloc((*n) * sizeof (int*));
    for (i = 0; i < (*n); i++)
        (*imageMatrix)[i] = (int*) malloc((*m) * sizeof (int));


    row = col = 0;
    while (fscanf(imageFile, "%d", &pixVal) != EOF) {
        (*imageMatrix)[row][col++] = pixVal;
        if (col >= (*m)) {
            col = 0;
            row++;
        }
        //		printf("%d ",pixVal);
    }

    /*
            for(i=0;i<(*n);i++)
            {
                    for(j=0;j<(*m);j++)
                    {
                            printf("%d ",(*imageMatrix)[i][j]);
                    }
                    printf("\n");
            }
     */
    fclose(imageFile);
}
