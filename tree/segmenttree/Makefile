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

# Segment Tree 1D

segment_tree_1d.o: $(SOURCEINCLUDE)/segment_tree_1d.h $(SOURCEPATH)/segment_tree_1d.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/segment_tree_1d.c -c
	mv segment_tree_1d.o $(BUILDPATH)/

main_segment_tree_1d: $(BUILDPATH) $(SOURCEPATH)/main_segment_tree_1d.c segment_tree_1d.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/segment_tree_1d.o $(SOURCEPATH)/main_segment_tree_1d.c -o main_segment_tree_1d
	mv main_segment_tree_1d $(BUILDPATH)/


# Segement Tree 2D

# fenwick_tree_2d.o: $(SOURCEINCLUDE)/fenwick_tree_2d.h $(SOURCEPATH)/fenwick_tree_2d.c
# 	$(COMPILER) $(FLAGS) $(SOURCEPATH)/fenwick_tree_2d.c -c
# 	mv fenwick_tree_2d.o $(BUILDPATH)/

# main_fenwick_tree_2d: $(BUILDPATH) $(SOURCEPATH)/main_fenwick_tree_2d.c fenwick_tree_2d.o
# 	$(COMPILER) $(FLAGS) $(BUILDPATH)/fenwick_tree_2d.o $(SOURCEPATH)/main_fenwick_tree_2d.c -o main_fenwick_tree_2d
# 	mv main_fenwick_tree_2d $(BUILDPATH)/
