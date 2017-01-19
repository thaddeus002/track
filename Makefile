
ifndef CC
CC=gcc
endif

all: track

track: track.o wsquery.o
	$(CC) -o track track.o wsquery.o

test_wsquery: test_wsquery.o wsquery.o
	$(CC) -o test_wsquery test_wsquery.o wsquery.o

%.o: %.c %.h
	$(CC) -Wall -c $<

clean:
	rm -f *.o *~

mrproper: clean
	rm -f track test_wsquery

test: test_wsquery
	test_wsquery
