CC=clang
WARNING=-Wall -Wextra
CFLAGS-DEBUG=-g $(WARNING) -Werror
CFLAGS-RELEASE=$(WARNING)
INCLUDE=-Iinclude

OBJ=build/obj
BIN=build/bin/$(OUT)

OUT=main
OBJS=$(OBJ)/main.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS-DEBUG) $(INCLUDE) $< -o $(BIN)
$(OBJ)/%.o: src/%.c
	$(CC) $(CFLAGS-DEBUG) $(INCLUDE) -c $< -o $@

clean:
	rm build/obj/* build/bin/*
