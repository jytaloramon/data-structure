COMPILER=gcc
FLAGS=-Wall

SOURCEPATH=src
SOURCEINCLUDE=include
BUILDPATH=build

#SRCfolderPATH=/folder

# General use

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

clear_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*

# Static Satck

static_stack.o: $(BUILDPATH) $(SOURCEINCLUDE)/static_stack.h $(SOURCEPATH)/static_stack.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/static_stack.c -c
	mv static_stack.o $(BUILDPATH)/

main_static_stack: $(BUILDPATH) $(SOURCEPATH)/main_static_stack.c static_stack.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/static_stack.o $(SOURCEPATH)/main_static_stack.c -o main_static_stack
	mv main_static_stack $(BUILDPATH)/

# Dynamic Stack

dynamic_stack.o: $(BUILDPATH) $(SOURCEINCLUDE)/dynamic_stack.h $(SOURCEPATH)/dynamic_stack.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/dynamic_stack.c -c
	mv dynamic_stack.o $(BUILDPATH)/

main_dynamic_stack: $(BUILDPATH) $(SOURCEPATH)/main_dynamic_stack.c dynamic_stack.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/dynamic_stack.o $(SOURCEPATH)/main_dynamic_stack.c -o main_dynamic_stack
	mv main_dynamic_stack $(BUILDPATH)/

