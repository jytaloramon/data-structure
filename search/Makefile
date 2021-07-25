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

# B_search

binary_search.o: $(SOURCEINCLUDE)/nsearch.h $(SOURCEPATH)/binary_search.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/binary_search.c -c
	mv binary_search.o $(BUILDPATH)/

main_nsearch_b: $(BUILDPATH) $(SOURCEPATH)/main_nsearch.c binary_search.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/binary_search.o \
		$(SOURCEPATH)/main_nsearch.c -o main_nsearch
	mv main_nsearch $(BUILDPATH)/

# T_search

ternary_search.o: $(SOURCEINCLUDE)/nsearch.h $(SOURCEPATH)/ternary_search.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/ternary_search.c -c
	mv ternary_search.o $(BUILDPATH)/

main_nsearch_t: $(BUILDPATH) $(SOURCEPATH)/main_nsearch.c ternary_search.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/ternary_search.o \
		$(SOURCEPATH)/main_nsearch.c -o main_nsearch
	mv main_nsearch $(BUILDPATH)/

