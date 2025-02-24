CC = gcc
CFLAGS = -g -Wall

OBJS = main.o memoize.o

all: money_to_text

money_to_text: $(OBJS)
	$(CC) -o money_to_text $(CFLAGS) $(OBJS)

main.o: main.c memoize.h
	$(CC) -c $(CFLAGS) main.c

memoize.o: memoize.c memoize.h
	$(CC) -c $(CFLAGS) memoize.c

clean:
	rm -f money_to_text $(OBJS)