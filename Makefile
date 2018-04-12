CC=g++
CFLAGS=-W -Wall -O3 -std=c++11
LDFLAGS= 
EXEC=test
SRC= test.cpp
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

test: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
