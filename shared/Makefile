PREFIX = /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

.PHONY: all clean install uninstall

all: test

test: test.c vector.h libvector.so
	gcc test.c -L. -lvector -o test

vector.o: vector.c vector.h
	gcc -fPIC -c vector.c -o vector.o

libvector.so: vector.o
	gcc -shared -o libvector.so vector.o

install: libvector.so vector.h
	cp vector.h $(INCDIR)
	chmod 664 $(INCDIR)/vector.h
	cp libvector.so $(LIBDIR)
	chmod 755 $(LIBDIR)/libvector.so

uninstall:
	rm -f $(INCDIR)/vector.h
	rm -f $(LIBDIR)/libvector.so

clean:
	rm -f vector.o libvector.so test