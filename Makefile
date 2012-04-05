CC=g++

all: sayan

sayan: imageSegment.o main.o readImage.o writeImage.o
	$(CC) imageSegment.o main.o readImage.o writeImage.o -o sayan

imageSegment.o: imageSegment.cpp writeImage.h
	$(CC) -c imageSegment.cpp

main.o: main.cpp
	$(CC) -c main.cpp

readImage.o: readImage.c
	$(CC) -c readImage.c

writeImage.o: writeImage.cpp
	$(CC) -c writeImage.cpp

.phony: clean


clean:
	rm *.o sayan
