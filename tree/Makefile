SOURCEPATH=src
BUILDPATH=build

COMPILER=gcc
FLAGS=-Wall

create_fold_build:
	mkdir $(BUILDPATH)

clear: $(BUILDPATH)
	rm -rf $(BUILDPATH)

rm_build: $(BUILDPATH)
	rm -rf $(BUILDPATH)/*
	
heap.o: $(SOURCEPATH)/heap.c $(BUILDPATH)
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/heap.c -c
	mv heap.o $(BUILDPATH)/

main_heap: $(SOURCEPATH)/main_heap.c heap.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/heap.o $(SOURCEPATH)/main_heap.c -o main_heap
	mv main_heap $(BUILDPATH)/ 
