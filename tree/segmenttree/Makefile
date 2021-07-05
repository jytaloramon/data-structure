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

segment_tree_1d.o: $(SOURCEINCLUDE)/segment_tree_1d_base.h \
		$(SOURCEPATH)/segment_tree_1d.c

	$(COMPILER) $(FLAGS) $(SOURCEPATH)/segment_tree_1d.c -c
	mv segment_tree_1d.o $(BUILDPATH)/

main_segment_tree_1d: $(BUILDPATH) $(SOURCEPATH)/main_segment_tree_1d.c segment_tree_1d.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/segment_tree_1d.o \
		$(SOURCEPATH)/main_segment_tree_1d.c -o main_segment_tree_1d
	mv main_segment_tree_1d $(BUILDPATH)/

# Segment Tree 1D Lazy

segment_tree_1d_lazy.o: $(SOURCEINCLUDE)/segment_tree_1d_base.h \
		$(SOURCEINCLUDE)/segment_tree_1d_lazy.h $(SOURCEPATH)/segment_tree_1d_lazy.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/segment_tree_1d_lazy.c -c
	mv segment_tree_1d_lazy.o $(BUILDPATH)/

main_segment_tree_1d_lazy: $(BUILDPATH) $(SOURCEPATH)/main_segment_tree_1d_lazy.c segment_tree_1d_lazy.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/segment_tree_1d_lazy.o \
		$(SOURCEPATH)/main_segment_tree_1d_lazy.c -o main_segment_tree_1d_lazy
	mv main_segment_tree_1d_lazy $(BUILDPATH)/


# Segement Tree 2D

segment_tree_2d.o: $(SOURCEINCLUDE)/segment_tree_2d.h $(SOURCEPATH)/segment_tree_2d.c segment_tree_1d.o
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/segment_tree_2d.c -c
	mv segment_tree_2d.o $(BUILDPATH)/

main_segment_tree_2d: $(BUILDPATH) $(SOURCEPATH)/main_segment_tree_2d.c segment_tree_2d.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/segment_tree_1d.o $(BUILDPATH)/segment_tree_2d.o \
		$(SOURCEPATH)/main_segment_tree_2d.c -o main_segment_tree_2d
	mv main_segment_tree_2d $(BUILDPATH)/
