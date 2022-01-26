COMPILER=gcc
FLAGS=-Wall

SRCPATH=src
SRCINCLUDE=include
BUILDPATH=build

SRCPROJECTLIST=../../list

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*


heap_fib.o: $(SRCPATH)/heap_fib.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/heap_fib.c -c
	mv heap_fib.o $(BUILDPATH)/

circular_doubly_linked_list.o: $(SRCPROJECTLIST)/$(SRCPATH)/circular_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTLIST)/$(SRCPATH)/circular_doubly_linked_list.c -c
	mv circular_doubly_linked_list.o $(BUILDPATH)/

main_heap_fib: $(BUILDPATH) circular_doubly_linked_list.o \
		heap_fib.o $(SRCPATH)/main_heap_fib.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/circular_doubly_linked_list.o \
		$(BUILDPATH)/heap_fib.o $(SRCPATH)/main_heap_fib.c -o main_heap_fib
	mv main_heap_fib $(BUILDPATH)/
