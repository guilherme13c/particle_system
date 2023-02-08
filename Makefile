CC		= g++
TARGET 	= main.exe
CFLAGS	= -g -O3
LIBS	= -lm
SRC		= main.cpp particles.cpp

all:
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LIBS)

clean:
	rm *.exe *.txt
