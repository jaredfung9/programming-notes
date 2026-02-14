CC=clang
CFLAGS=-g -Wall
SRC=src
INC=include
OBJ=obj
BIN=bin
OUT=$(BIN)/main

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))


TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

.PHONY: all
all: $(BIN) $(SRC) $(OBJ) $(INC) $(TEST) $(OUT)

.PHONY: run
run: $(OUT)
	./$(OUT)

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

TESTOBJS=$(patsubst $(OBJ)/main.o,,$(OBJS))
$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) $< $(TESTOBJS) -lcriterion -o $@

$(TEST)/bin:
	mkdir $@
$(TEST):
	mkdir $@
$(BIN):
	mkdir $@
$(SRC):
	mkdir $@
$(OBJ):
	mkdir $@
$(INC):
	mkdir $@

.PHONY: test
test: $(OBJS) $(TEST)/bin $(TESTBINS)
	@for test in $(TESTBINS) ; do ./$$test ; done

.PHONY: clean
clean:
	rm -r bin/* obj/* tests/bin/*
