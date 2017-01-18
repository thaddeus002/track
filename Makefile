
ifndef CC
CC=gcc
endif

all: track

track: track.o wsquery.o

%.o: %.c %.h
	$(CC) -Wall -c $<

clean:
	rm -f *.o *~

mrproper: clean
	rm -f track

