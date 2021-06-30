CC = g++
CFLAGS = -g -Wall -Wextra -O3 -lm

main: main.o Face.o Camera.o Mesh.o Rasterizer.o Rotate.o Scale.o Translate.o lodepng.o
	$(CC) $(CFLAGS) main.o Camera.o Face.o Mesh.o Rasterizer.o Rotate.o Scale.o Translate.o lodepng.o -o main

Camera.o: Camera.h Camera.cpp
	$(CC) $(CFLAGS) -c Camera.cpp

Face.o: Face.h Face.cpp
	$(CC) $(CFLAGS) -c Face.cpp

Mesh.o: Face.h Face.cpp Mesh.h Mesh.cpp
	$(CC) $(CFLAGS) -c Mesh.cpp

Rasterizer.o: Rasterizer.h Rasterizer.cpp Face.h Face.cpp Mesh.h Mesh.cpp
	$(CC) $(CFLAGS) -c Rasterizer.cpp

Rotate.o: Rotate.h Rotate.cpp
	$(CC) $(CFLAGS) -c Rotate.cpp

Scale.o: Scale.h Scale.cpp
	$(CC) $(CFLAGS) -c Scale.cpp

Translate.o: Translate.h Translate.cpp
	$(CC) $(CFLAGS) -c Translate.cpp

lodepng.o: lodepng.h lodepng.cpp
	$(CC) $(CFLAGS) -c lodepng.cpp

main.o: main.cpp Camera.h Face.h Mesh.h Rasterizer.h Rotate.h Scale.h Translate.h lodepng.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main
