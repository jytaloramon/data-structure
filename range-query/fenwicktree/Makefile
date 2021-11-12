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

# Fenwick Tree 1D

fenwick_tree_1d.o: $(SOURCEINCLUDE)/fenwick_tree_1d.h $(SOURCEPATH)/fenwick_tree_1d.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/fenwick_tree_1d.c -c
	mv fenwick_tree_1d.o $(BUILDPATH)/

main_fenwick_tree_1d: $(BUILDPATH) $(SOURCEPATH)/main_fenwick_tree_1d.c fenwick_tree_1d.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/fenwick_tree_1d.o \
		$(SOURCEPATH)/main_fenwick_tree_1d.c -o main_fenwick_tree_1d
	mv main_fenwick_tree_1d $(BUILDPATH)/


# Fenwick Tree 2D

fenwick_tree_2d.o: $(SOURCEINCLUDE)/fenwick_tree_2d.h $(SOURCEPATH)/fenwick_tree_2d.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/fenwick_tree_2d.c -c
	mv fenwick_tree_2d.o $(BUILDPATH)/

main_fenwick_tree_2d: $(BUILDPATH) $(SOURCEPATH)/main_fenwick_tree_2d.c fenwick_tree_2d.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/fenwick_tree_2d.o \
		$(SOURCEPATH)/main_fenwick_tree_2d.c -o main_fenwick_tree_2d
	mv main_fenwick_tree_2d $(BUILDPATH)/
