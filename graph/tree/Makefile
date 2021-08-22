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

binary_tree.o: $(SOURCEINCLUDE)/binary_tree.h $(SOURCEPATH)/binary_tree.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/binary_tree.c -c
	mv binary_tree.o $(BUILDPATH)/

main_binary_tree: $(BUILDPATH) $(SOURCEPATH)/main_binary_tree.c binary_tree.o
	$(COMPILER) $(FLAGS) $(BUILDPATH)/binary_tree.o \
		$(SOURCEPATH)/main_binary_tree.c -o main_binary_tree
	mv main_binary_tree $(BUILDPATH)/