COMPILER=gcc
FLAGS=-Wall

SOURCEPATH=src
SOURCEINCLUDE=include
BUILDPATH=build

SRCMATHPATH=../math

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

# List Static 

arithmetic.o: $(BUILDPATH) $(SRCMATHPATH)/$(SOURCEINCLUDE)/arithmetic.h $(SRCMATHPATH)/$(SOURCEPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCMATHPATH)/$(SOURCEPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

static_list.o: $(BUILDPATH) $(SOURCEINCLUDE)/static_list.h $(SOURCEPATH)/static_list.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/static_list.c -c
	mv static_list.o $(BUILDPATH)/

main_static_list: $(BUILDPATH) static_list.o arithmetic.o $(SOURCEPATH)/main_static_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/static_list.o $(BUILDPATH)/arithmetic.o $(SOURCEPATH)/main_static_list.c -o main_static_list
	mv main_static_list $(BUILDPATH)/
	

# Doubly Linked List

doubly_linked_list.o: $(BUILDPATH) $(SOURCEINCLUDE)/doubly_linked_list.h $(SOURCEPATH)/doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/doubly_linked_list.c -c
	mv doubly_linked_list.o $(BUILDPATH)/

main_doubly_linked_list: $(BUILDPATH) doubly_linked_list.o $(SOURCEPATH)/main_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/doubly_linked_list.o $(SOURCEPATH)/main_doubly_linked_list.c -o main_doubly_linked_list
	mv main_doubly_linked_list $(BUILDPATH)/


# Circular Doubly Linked List

circular_doubly_linked_list.o: $(BUILDPATH) $(SOURCEINCLUDE)/circular_doubly_linked_list.h $(SOURCEPATH)/circular_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/circular_doubly_linked_list.c -c
	mv circular_doubly_linked_list.o $(BUILDPATH)/

main_circular_doubly_linked_list: $(BUILDPATH) circular_doubly_linked_list.o $(SOURCEPATH)/main_circular_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/circular_doubly_linked_list.o $(SOURCEPATH)/main_circular_doubly_linked_list.c -o main_circular_doubly_linked_list
	mv main_circular_doubly_linked_list $(BUILDPATH)/
