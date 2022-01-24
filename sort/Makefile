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


arithmetic.o: $(BUILDPATH) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c
	$(COMPILER) $(FLAGS) $(SRCPROJECTMATH)/$(SRCPATH)/arithmetic.c -c
	mv arithmetic.o $(BUILDPATH)/

selection_sort.o: $(SRCPATH)/selection_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/selection_sort.c -c
	mv selection_sort.o $(BUILDPATH)/

bubble_sort.o: $(SRCPATH)/bubble_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/bubble_sort.c -c
	mv bubble_sort.o $(BUILDPATH)/

insertion_sort.o: $(SRCPATH)/insertion_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/insertion_sort.c -c
	mv insertion_sort.o $(BUILDPATH)/

merge_sort.o: $(SRCPATH)/merge_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/merge_sort.c -c
	mv merge_sort.o $(BUILDPATH)/

quick_sort.o: $(SRCPATH)/quick_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/quick_sort.c -c
	mv quick_sort.o $(BUILDPATH)/

tim_sort.o: $(SRCPATH)/tim_sort.c
	$(COMPILER) $(FLAGS) $(SRCPATH)/tim_sort.c -c
	mv tim_sort.o $(BUILDPATH)/


main_selection_sort: selection_sort.o $(SRCPATH)/main_sort.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/selection_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_bubble_sort: bubble_sort.o $(SRCPATH)/main_sort.c 
	$(COMPILER) $(FLAGS) $(BUILDPATH)/bubble_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_insertion_sort: insertion_sort.o$(SRCPATH)/main_sort.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/insertion_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_merge_sort: merge_sort.o $(SRCPATH)/merge_sort.c 
	$(COMPILER) $(FLAGS) $(BUILDPATH)/merge_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_quick_sort: quick_sort.o $(SRCPATH)/quick_sort.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/quick_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_tim_sort: arithmetic.o insertion_sort.o \
		merge_sort.o tim_sort.o $(SRCPATH)/tim_sort.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/arithmetic.o $(BUILDPATH)/tim_sort.o  \
		$(BUILDPATH)/insertion_sort.o  $(BUILDPATH)/merge_sort.o \
		$(SRCPATH)/main_sort.c -o main_sort
	mv main_sort $(BUILDPATH)/

main_sort_tests: arithmetic.o insertion_sort.o \
		merge_sort.o tim_sort.o $(SRCPATH)/tim_sort.c
	$(COMPILER) $(FLAGS) $(BUILDPATH)/arithmetic.o $(BUILDPATH)/tim_sort.o  \
		$(BUILDPATH)/insertion_sort.o  $(BUILDPATH)/merge_sort.o \
		$(SRCPATH)/main_sort_tests.c -o main_sort_tests
	mv main_sort_tests $(BUILDPATH)/
