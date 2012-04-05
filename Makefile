CC=gcc

all: mri

mri: imageSegment.o main.o readImage.o writeImage.o
	$(CC) imageSegment.o main.o readImage.o writeImage.o -o mri

imageSegment.o: imageSegment.c writeImage.h
	$(CC) -c imageSegment.c

main.o: main.c
	$(CC) -c main.c

readImage.o: readImage.c
	$(CC) -c readImage.c

writeImage.o: writeImage.c
	$(CC) -c writeImage.c

.phony: clean


clean:
	-rm *.o mri
