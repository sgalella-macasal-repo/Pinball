CC = gcc
CFLAGS = -Wall -Iinclude

vpath %.c src
vpath %.h include

build_dir = build
bin_dir = bin

.PHONY: all

all: main

main: $(build_dir)/main.o $(build_dir)/pinball.o
	$(CC) $(CFLAGS) $^ -o $(bin_dir)/$@

$(build_dir)/main.o: main.c pinball.h
	$(CC) $(CFLAGS) -c $< -o $@

$(build_dir)/pinball.o: pinball.c pinball.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm bin/*  build/*