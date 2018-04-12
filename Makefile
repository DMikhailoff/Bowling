CC=g++
CFLAGS=-W -Wall -O3 -std=c++11
LDFLAGS= 


TEST=tests.exe
PROG=bowling.exe


TEST_SRC= test.cpp
TEST_OBJ= $(TEST_SRC:.cpp=.o)

PROG_SRC= main.cpp
PROG_OBJ= $(PROG_SRC:.cpp=.o)



all: $(PROG) #si on ecrit make tout seul il compile juste le programme bowling

$(TEST): $(TEST_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

tests:$(TEST) #si on ecrit make tests il vient ici

$(PROG): $(PROG_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

bowling: $(PROG) #si on ecrit make bowling il vient ici

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(TEST)
	rm $(PROG)
