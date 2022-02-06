COMPILER=gcc
FLAGS=-Wall

SRCPATH=src
SRCINCLUDE=include
BUILDPATH=build

SRCPROJECTMATH=../math
SRCPROJECTLIST=../list


# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

# Static Satck

arithmetic.o: $(BUILDPATH) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

static_list.o: $(BUILDPATH) $(SRCPROJECTLIST)/$(SRCPATH)/static_list.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTLIST)/$(SRCPATH)/static_list.c -c
	mv static_list.o $(BUILDPATH)/

static_stack.o: $(BUILDPATH) $(SRCPATH)/static_stack.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/static_stack.c -c
	mv static_stack.o $(BUILDPATH)/

main_static_stack: arithmetic.o static_list.o static_stack.o $(SRCPATH)/main_static_stack.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/arithmetic.o $(BUILDPATH)/static_list.o \
		$(BUILDPATH)/static_stack.o $(SRCPATH)/main_static_stack.c -o main_static_stack
	mv main_static_stack $(BUILDPATH)/

# Dynamic Stack

linked_list.o: $(BUILDPATH) $(SRCPROJECTLIST)/$(SRCPATH)/linked_list.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTLIST)/$(SRCPATH)/linked_list.c -c
	mv linked_list.o $(BUILDPATH)/

dynamic_stack.o: $(BUILDPATH) $(SRCPATH)/dynamic_stack.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/dynamic_stack.c -c
	mv dynamic_stack.o $(BUILDPATH)/

main_dynamic_stack: $(BUILDPATH) linked_list.o dynamic_stack.o \
		$(SRCPATH)/main_dynamic_stack.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/linked_list.o $(BUILDPATH)/dynamic_stack.o \
		$(SRCPATH)/main_dynamic_stack.c -o main_dynamic_stack
	mv main_dynamic_stack $(BUILDPATH)/
