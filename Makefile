CFLAGS := -Wall -Werror -g -pthread

all: tally tally.s

tally: tally.o

tally.s: tally.c
	$(CC) -S $<

clean:
	rm -f tally tally.s *.o *~
