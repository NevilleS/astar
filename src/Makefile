CC = g++
CCFLAGS = -g -O2
SRC := PriorityQueue.cpp \
	   StdQueue.cpp \
	   Stack.cpp \
	   Node.cpp \
	   Path.cpp \
	   Map.cpp \
	   Net.cpp \
	   Search.cpp \
	   Solver.cpp \
	   Block.cpp 
OBJ := $(SRC:.cpp=.o)
TEST_SRC := QueueTest.cpp \
			MapTest.cpp \
			SearchTest.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
MAIN = main.c
BIN = search
TEST = test

default: all

all: $(BIN) $(TEST)

$(BIN): $(OBJ) $(MAIN)
	$(CC) $(CCFLAGS) $(OBJ) $(MAIN) -o $@

$(OBJ): $(SRC)
	$(CC) $(CCFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CCFLAGS) -I/usr/local/include -c $< -o $@

$(TEST): $(TEST_OBJ) $(OBJ)
	$(CC) $(TEST_OBJ) $(OBJ) -L/usr/local/lib -lgtest_main -o $@


.PHONY: clean obj lib bin src runtest
clean:
	rm $(BIN) $(OBJ) $(TEST_OBJ)

obj: $(OBJ)

bin: $(BIN)

runtest: $(TEST)
	./$(TEST)
