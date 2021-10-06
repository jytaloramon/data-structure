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

main_boyer_moore: $(BUILDPATH) $(SOURCEPATH)/main_boyer_moore.c
	$(COMPILER) $(FLAGS) $(SOURCEPATH)/main_boyer_moore.c -o main_boyer_moore
	mv main_boyer_moore $(BUILDPATH)/