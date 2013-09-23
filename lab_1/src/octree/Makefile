CC=g++
CFLAGS=-Wall
LDFLAGS=-lGL -lGLU -lglut

DEPS=../../include/octree_fn.h
OBJ=../../obj/octree.o ../../obj/octree_fn.o

all: octree

../../obj/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

octree: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	 rm -f *~ ../../obj/*.o octree
