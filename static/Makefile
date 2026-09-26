PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

.PHONY: all clean install uninstall

all: test

test: test.c vector.h libvector.a
	gcc test.c -L. -lvector -o test

vector.o: vector.c vector.h
	gcc -c vector.c -o vector.o

libvector.a: vector.o
	ar rcs libvector.a vector.o

install: libvector.a vector.h
	cp vector.h $(INCDIR)
	chmod 664 $(INCDIR)/vector.h
	cp libvector.a $(LIBDIR)
	chmod 755 $(LIBDIR)/libvector.a

uninstall:
	rm -f $(INCDIR)/vector.h
	rm -f $(LIBDIR)/libvector.a

clean:
	rm -f vector.o libvector.a test