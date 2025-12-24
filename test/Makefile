OBJS = TextureTest.cpp
CC = g++
COMPILER_FLAGS = -Wall -std=c++11
LINKER_FLAGS = -lSDL3 -lSDL3_image -lSDL3_ttf
INCLUDE = -I/usr/local/include
SDL3_LIB = -L/usr/local/lib
OBJ_NAME = Executables/exe

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDE) $(SDL3_LIB) $(LINKER_FLAGS) -o $(OBJ_NAME)
