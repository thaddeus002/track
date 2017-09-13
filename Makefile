
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

libmap.a:
	make -C lib/libmap/src libmap.a
	mv lib/libmap/src/libmap.a .

clean:
	make -C lib/libmap/src clean
	rm -f *.o *~

mrproper: clean
	make -C lib/libmap/src mrproper
	rm -f track test_wsquery *.a

test: test_wsquery
	test_wsquery
