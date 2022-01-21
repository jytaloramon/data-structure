COMPILER=gcc
FLAGS=-Wall

SOURCEPATH=src
SOURCEINCLUDE=include
BUILDPATH=build

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

heap_fib.o: $(SOURCEINCLUDE)/heap.h $(SOURCEPATH)/heap_fib.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/heap_fib.c -c
	mv heap_fib.o $(BUILDPATH)/

main_heap_fib: $(BUILDPATH) $(SOURCEPATH)/main_heap_fib.c heap_fib.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/heap.o \
		$(SOURCEPATH)/main_heap_fib.c -o main_heap_fib
	mv main_heap_fib $(BUILDPATH)/
	