CC		= g++
TARGET 	= bin/main.exe
CFLAGS	= -g -O3
LIBS	= -lm
SRC		= src/main.cpp src/particles.cpp
INCLUDE = include

all:
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LIBS) -I$(INCLUDE)

clean:
	rm *.exe *.txt
