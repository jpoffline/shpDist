# Compilation flags

OPTIMIZE = -O3 -march=native -flto
WARNINGS = -Wall -Wextra -Wno-unused-parameter

CC = g++

CFLAGS = $(OPTIMIZE) $(WARNINGS) -std=gnu++03
<<<<<<< HEAD
#INC = -I/usr/local/include
#LIBS = -L/usr/local/lib -lm -lgsl -lgslcblas 
=======
INC = -I/usr/local/include
LIBS = -L/usr/local/lib -lm -lgsl -lgslcblas 
>>>>>>> d5975d2ff872bee0e34d30aa60a0cc452fac94cf

# Make rules

OBJECTS = COORD_CONVERT.o CREATE_DIST.o TEST_LOCATION.o TUPLE.o HISTOGRAM.o

OBJECTMAIN = shpDist.o 


.PHONY: all
all: main 

main: $(OBJECTS) $(OBJECTMAIN)
<<<<<<< HEAD
	$(CC) $(OBJECTS) $(OBJECTMAIN) -o $@
=======
	$(CC) $(OBJECTS) $(OBJECTMAIN) $(LIBS) -o $@
>>>>>>> d5975d2ff872bee0e34d30aa60a0cc452fac94cf

clean:
	-rm -rf $(OBJECTS) $(OBJECTMAIN) main


