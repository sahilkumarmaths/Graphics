all: main program
	g++ -Wall  ../obj/main.o ../obj/program.o -lGL -lGLU -lglut -o ../bin/out

main:
	g++ -Wall -c  -lGL -lGLU -lglut main.cpp  -o ../obj/main.o

program:
	g++ -Wall -c -lGL -lGLU -lglut program.cpp -o ../obj/program.o

clean:
	rm ../obj/*.o
