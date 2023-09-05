# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Source files
SRC = main.c alocator.c algorithms.c menu.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXE = algorithmsManager

# Targets and rules
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

.PHONY: all clean

