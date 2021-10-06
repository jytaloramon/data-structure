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

heap.o: $(SOURCEINCLUDE)/heap.h $(SOURCEPATH)/heap.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/heap.c -c
	mv heap.o $(BUILDPATH)/

main_heap: $(BUILDPATH) $(SOURCEPATH)/main_heap.c heap.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/heap.o \
		$(SOURCEPATH)/main_heap.c -o main_heap
	mv main_heap $(BUILDPATH)/