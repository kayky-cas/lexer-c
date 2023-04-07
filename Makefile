CFLAGS = -Wall -O2

PROG = main
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

$(PROG): $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $@

clear:
	-@ rm -f $(OBJECTS) $(PROG)
