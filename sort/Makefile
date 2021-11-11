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


selection_sort.o: $(SOURCEINCLUDE)/selection_sort.h $(SOURCEPATH)/selection_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/selection_sort.c -c
	mv selection_sort.o $(BUILDPATH)/

bubble_sort.o: $(SOURCEINCLUDE)/bubble_sort.h $(SOURCEPATH)/bubble_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/bubble_sort.c -c
	mv bubble_sort.o $(BUILDPATH)/

insertion_sort.o: $(SOURCEINCLUDE)/insertion_sort.h $(SOURCEPATH)/insertion_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/insertion_sort.c -c
	mv insertion_sort.o $(BUILDPATH)/

merge_sort.o: $(SOURCEINCLUDE)/merge_sort.h $(SOURCEPATH)/merge_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/merge_sort.c -c
	mv merge_sort.o $(BUILDPATH)/

quick_sort.o: $(SOURCEINCLUDE)/quick_sort.h $(SOURCEPATH)/quick_sort.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/quick_sort.c -c
	mv quick_sort.o $(BUILDPATH)/


main_sort_selection: $(BUILDPATH) $(SOURCEPATH)/main_sort.c selection_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/selection_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_bubble: $(BUILDPATH) $(SOURCEPATH)/main_sort.c bubble_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/bubble_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_insertion: $(BUILDPATH) $(SOURCEPATH)/main_sort.c insertion_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/insertion_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_merge: $(BUILDPATH) $(SOURCEPATH)/merge_sort.c merge_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/merge_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_quick: $(BUILDPATH) $(SOURCEPATH)/quick_sort.c quick_sort.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/quick_sort.o \
		$(SOURCEPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/