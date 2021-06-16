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

# Static Queue

arithmetic.o: $(BUILDPATH) $(SRCMATHPATH)/$(SOURCEINCLUDE)/arithmetic.h $(SRCMATHPATH)/$(SOURCEPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCMATHPATH)/$(SOURCEPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

static_queue.o: $(BUILDPATH) $(SOURCEINCLUDE)/static_queue.h $(SOURCEPATH)/static_queue.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/static_queue.c -c
	mv static_queue.o $(BUILDPATH)/

main_static_queue: $(BUILDPATH) $(SOURCEPATH)/main_static_queue.c static_queue.o arithmetic.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/static_queue.o $(BUILDPATH)/arithmetic.o $(SOURCEPATH)/main_static_queue.c -o main_static_queue
	mv main_static_queue $(BUILDPATH)/

# Dynamic Queue

dynamic_queue.o: $(BUILDPATH) $(SOURCEINCLUDE)/dynamic_queue.h $(SOURCEPATH)/dynamic_queue.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/dynamic_queue.c -c
	mv dynamic_queue.o $(BUILDPATH)/

main_dynamic_queue: $(BUILDPATH) $(SOURCEPATH)/main_dynamic_queue.c dynamic_queue.o arithmetic.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/dynamic_queue.o $(BUILDPATH)/arithmetic.o $(SOURCEPATH)/main_dynamic_queue.c -o main_dynamic_queue
	mv main_dynamic_queue $(BUILDPATH)/
