CC=gcc
SRC=./alloc.c ./utils.c
OUTPUT=./alloc
FLAGS=-g -O0 -Wall -Wextra -fsanitize=address

all:
	$(CC) $(FLAGS) -o $(OUTPUT) $(SRC)

run:
	$(OUTPUT) $(ARGS)

clean:
	rm -rf $(OUTPUT)

fall:
	$(CC) $(FLAGS) -o $(OUTPUT) $(SRC)

