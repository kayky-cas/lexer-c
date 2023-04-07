CFLAGS = -Wall -O2

PROG = main
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

$(PROG): $(OBJECTS)
	mkdir -p out
	gcc $(CFLAGS) $(OBJECTS) -o ./out/$@

clear:
	-@ rm -f ./out/*
