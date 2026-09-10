CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
CPPFLAGS = -Iinclude

SRCS = src/main.c src/tokenizer.c
OBJS = $(SRCS:.c=.o)

.PHONY: all test clean

all: unix-shell

unix-shell: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

src/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

test: tests/test_tokenizer.c src/tokenizer.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o test_tokenizer tests/test_tokenizer.c src/tokenizer.c
	./test_tokenizer

clean:
	rm -f $(OBJS) unix-shell test_tokenizer
