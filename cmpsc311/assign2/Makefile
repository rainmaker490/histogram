# Makefile - for simpler compilation and linking

#Variables

CC = gcc
LINK = gcc
CFLAGS = -c -Wall -I.
OBJECT_FILES = a2support.o cmpsc311-f13-assign2.o

# Suffix rules
.SUFFIXES: .c .o

.c.o:
	 $(CC) -c $(CFLAGS) -o $@ $<

#Productions
assign2 : $(OBJECT_FILES) 
	 $(LINK) $(OBJECT_FILES) -o $@ 

# Dependancies
a2support.o : a2support.c a2support.h
cmpsc311-f13-assign2.o : cmpsc311-f13-assign2.c
