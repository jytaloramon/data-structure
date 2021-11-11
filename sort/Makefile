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

bubble_sort.o: $(SOURCEINCLUDE)/bubble_sort.h $(SOURCEPATH)/bubble_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/bubble_sort.c -c
	mv bubble_sort.o $(BUILDPATH)/

quick_sort.o: $(SOURCEINCLUDE)/quick_sort.h $(SOURCEPATH)/quick_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/quick_sort.c -c
	mv quick_sort.o $(BUILDPATH)/

main_sort_bubble: $(BUILDPATH) $(SOURCEPATH)/main_sort.c bubble_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/bubble_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_quick: $(BUILDPATH) $(SOURCEPATH)/quick_sort.c quick_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/quick_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/