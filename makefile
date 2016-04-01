# Compilation flags

OPTIMIZE = -O3 -march=native -flto
WARNINGS = -Wall -Wextra -Wno-unused-parameter

CC = g++

CFLAGS = $(OPTIMIZE) $(WARNINGS) -std=gnu++03
#INC = -I/usr/local/include
#LIBS = -L/usr/local/lib -lm -lgsl -lgslcblas 

# Make rules

OBJECTS = COORD_CONVERT.o CREATE_DIST.o TEST_LOCATION.o TUPLE.o HISTOGRAM.o

OBJECTMAIN = shpDist.o 


.PHONY: all
all: main 

main: $(OBJECTS) $(OBJECTMAIN)
	$(CC) $(OBJECTS) $(OBJECTMAIN) -o $@

clean:
	-rm -rf $(OBJECTS) $(OBJECTMAIN) main


