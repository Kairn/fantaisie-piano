#OBJS SOURCE FILES
OBJS = fpMain.cxx fpClasses.cxx

#C COMPILER
CC = g++

#COMPILER_FLAGS COMPILATION OPTIONS
COMPILER_FLAGS = -w -std=c++11

#LINKERS LIBRARIES
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#EXE_NAME EXECUTABLE FILE
EXE_NAME = fantaisie_piano

#MAKE COMMAND
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXE_NAME)
