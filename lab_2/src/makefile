all: main cube sphere objects
	g++ -Wall  ../obj/main.o ../obj/sphere.o ../obj/cube.o ../obj/objects.o -lGL -lGLU -lglut -o ../bin/out

main:
	g++ -Wall -c  -lGL -lGLU -lglut main.cpp  -o ../obj/main.o

cube:
	g++ -Wall -c -lGL -lGLU -lglut sphere.cpp -o ../obj/cube.o

sphere:
	g++ -Wall -c -lGL -lGLU -lglut cube.cpp -o ../obj/sphere.o

objects:
	g++ -Wall -c -lGL -lGLU -lglut objects.cpp -o ../obj/objects.o

clean:
	rm ../obj/*.o
