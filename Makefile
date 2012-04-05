CC=gcc
COMPILER_OPTIONS=-Wall -pedantic

all: mri

mri: imageSegment.o main.o readImage.o writeImage.o
	$(CC) $(COMPILER_OPTIONS) imageSegment.o main.o readImage.o writeImage.o -o mri

imageSegment.o: imageSegment.c writeImage.h
	$(CC) $(COMPILER_OPTIONS) -c imageSegment.c

main.o: main.c
	$(CC) $(COMPILER_OPTIONS) -c main.c

readImage.o: readImage.c
	$(CC) $(COMPILER_OPTIONS) -c readImage.c

writeImage.o: writeImage.c
	$(CC) $(COMPILER_OPTIONS) -c writeImage.c

.phony: clean


clean:
	-rm *.o mri
	-rm -r segmented_source
