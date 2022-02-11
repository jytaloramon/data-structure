COMPILER=gcc
FLAGS=-Wall

SRCPATH=src
SRCINCLUDE=include
BUILDPATH=build

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

heap_b.o: $(SRCPATH)/heap_b.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/heap_b.c -c
	mv heap_b.o $(BUILDPATH)/

main_heap_b: $(BUILDPATH) heap_b.o $(SRCPATH)/main_heap_b.c 
	$(COMPILER) $(FLAGS) $(BUILDPATH)/heap_b.o \
		$(SRCPATH)/main_heap_b.c -o main_heap_b
	mv main_heap_b $(BUILDPATH)/
