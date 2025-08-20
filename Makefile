CC := g++
# CC := gcc
CFLAGS := -O3 -std=c++17 -fno-fast-math -march=x86-64 -m128bit-long-double
#CFLAGS := -O3 -std=c++17 -fno-fast-math -mfpmath=sse -march=x86-64 -m128bit-long-double

SRCS := $(wildcard *.c) 
OBJS := $(SRCS:.c=.o)
EXES := main
TARGETS = main
INCLUDES := -I. -I/usr/local/include
LDFLAGS := -L/usr/local/lib/
LIBS := -lm -llapacke -llapack -lblas


#=================================================
all: $(TARGETS)

# Link all object files into the executable
$(TARGETS): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS) $(LIBS) 

# Compile each .c into a .o
%.o: %.c %.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Also handle .c files without headers
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#-------------------------------
# Clean up directory -- remove executables and intermediate files.
clean:
	-rm -f *~ *.o *.obj *.out *.map $(TARGETS) $(OBJS)
