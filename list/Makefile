COMPILER=gcc
FLAGS=-Wall

SRCPATH=src
SRCINCLUDE=include
BUILDPATH=build

SRCPROJECTMATH=../math

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

# Static List 

arithmetic.o: $(BUILDPATH) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

static_list.o: $(BUILDPATH) $(SRCPATH)/static_list.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/static_list.c -c
	mv static_list.o $(BUILDPATH)/

main_static_list: static_list.o arithmetic.o $(SRCPATH)/main_static_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/static_list.o $(BUILDPATH)/arithmetic.o \
		$(SRCPATH)/main_static_list.c -o main_static_list
	mv main_static_list $(BUILDPATH)/
	

# Doubly Linked List

doubly_linked_list.o: $(BUILDPATH) $(SRCPATH)/doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/doubly_linked_list.c -c
	mv doubly_linked_list.o $(BUILDPATH)/

main_doubly_linked_list: doubly_linked_list.o $(SRCPATH)/main_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/doubly_linked_list.o \
		$(SRCPATH)/main_doubly_linked_list.c -o main_doubly_linked_list
	mv main_doubly_linked_list $(BUILDPATH)/


# Circular Doubly Linked List

circular_doubly_linked_list.o: $(BUILDPATH) $(SRCPATH)/circular_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/circular_doubly_linked_list.c -c
	mv circular_doubly_linked_list.o $(BUILDPATH)/

main_circular_doubly_linked_list: circular_doubly_linked_list.o $(SRCPATH)/main_circular_doubly_linked_list.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/circular_doubly_linked_list.o \
		$(SRCPATH)/main_circular_doubly_linked_list.c -o main_circular_doubly_linked_list
	mv main_circular_doubly_linked_list $(BUILDPATH)/
