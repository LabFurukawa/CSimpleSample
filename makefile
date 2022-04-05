.PHONY : clean test help

CC := gcc
CFLAGS := -Iinclude
CPPFLAGS :=
LDFLAGS :=
LDLIBS :=

build/a.out : src/source.c build/tmp/css_sum.o build/tmp/css_prod.o
	@mkdir -p build
	$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) src/source.c build/tmp/css_sum.o build/tmp/css_prod.o

build/tmp/css_sum.o : include/css_error.h include/css_sum.h src/css_sum.c
	@mkdir -p build/tmp/
	$(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) src/css_sum.c

build/tmp/css_prod.o : include/css_error.h include/css_prod.h src/css_prod.c
	@mkdir -p build/tmp/
	$(CC) -c -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) src/css_prod.c

clean :
	@rm -rf build
	@echo "Remove \"build\""

test:
	./build/a.out

help:
	@echo "(default) : Compile"
	@echo "    clean : Clean"
	@echo "     test : Run"
	@echo "     help : This"