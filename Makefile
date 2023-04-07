CFLAGS = -Wall -O2

PROG = main
SOURCES = main.c

$(PROG): $(OBJECTS)
	mkdir -p out
	gcc $(CFLAGS) $(SOURCES) -o ./out/$@
	./out/$@

clear:
	-@ rm -f ./out/*
