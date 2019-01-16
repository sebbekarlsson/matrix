OS := $(shell uname)

$(info $(OS))

FLAGZ=-Wall -g -fPIC

SOURCES := $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

#test:\
#    $(OBJECTS) unit.o
#	gcc\
#	    $(OBJECTS) unit.o -o test.out -ldl -fPIC -lcmocka

#unit.o: src/unit/unit.c
#	gcc -g -Wall -c src/unit/unit.c -ldl -fPIC -lcmocka

%.o: %.c includes/%.h
	gcc -c $(FLAGZ) $< -o $@

libmatrix.so: $(OBJECTS)
	$(LINK.c) -shared $^ -o $@


install:
	-rm /usr/local/lib/libmatrix.*
	-rm -rf /usr/local/include/matrix
	make
	make libmatrix.so
	cp -r src/include /usr/local/include/matrix
	cp libmatrix.so /usr/local/lib/libmatrix.so

clean:
	-rm *.out
	-rm *.o
	-rm *.so
	-rm src/*.o
