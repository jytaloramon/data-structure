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

# Static Queue

arithmetic.o: $(BUILDPATH) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

static_list.o: $(BUILDPATH) $(SRCPROJECTLIST)/$(SRCPATH)/static_list.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTLIST)/$(SRCPATH)/static_list.c -c
	mv static_list.o $(BUILDPATH)/

static_queue.o: $(BUILDPATH) $(SRCPATH)/static_queue.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/static_queue.c -c
	mv static_queue.o $(BUILDPATH)/

main_static_queue: static_list.o arithmetic.o static_queue.o $(SRCPATH)/main_static_queue.c 
	$(COMPILER) $(FLAGS) $(BUILDPATH)/arithmetic.o $(BUILDPATH)/static_list.o  \
		$(BUILDPATH)/static_queue.o  $(SRCPATH)/main_static_queue.c -o main_static_queue
	mv main_static_queue $(BUILDPATH)/

# Dynamic Queue

linked_list.o: $(BUILDPATH) $(SRCPROJECTLIST)/$(SRCPATH)/linked_list.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTLIST)/$(SRCPATH)/linked_list.c -c
	mv linked_list.o $(BUILDPATH)/

dynamic_queue.o: $(BUILDPATH) $(SRCPATH)/dynamic_queue.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/dynamic_queue.c -c
	mv dynamic_queue.o $(BUILDPATH)/

main_dynamic_queue: $(BUILDPATH) linked_list.o dynamic_queue.o \
		$(SRCPATH)/main_dynamic_queue.c 
	$(COMPILER) $(FLAGS) $(BUILDPATH)/linked_list.o $(BUILDPATH)/dynamic_queue.o \
		$(SRCPATH)/main_dynamic_queue.c -o main_dynamic_queue
	mv main_dynamic_queue $(BUILDPATH)/
