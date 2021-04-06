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

binary_tree.o:  $(SOURCEPATH)/binary_tree.c $(BUILDPATH)
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/binary_tree.c -c
	mv binary_tree.o $(BUILDPATH)/

main_heap: $(SOURCEPATH)/main_heap.c heap.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/heap.o $(SOURCEPATH)/main_heap.c -o main_heap
	mv main_heap $(BUILDPATH)/ 

main_binary_tree: $(SOURCEPATH)/binary_tree.c binary_tree.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/binary_tree.o $(SOURCEPATH)/main_binary_tree.c -o main_binary_tree
	mv main_binary_tree $(BUILDPATH)/ 
