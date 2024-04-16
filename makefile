# Compiler to use
CC = gcc

# Compiler flags, -Wall enables all warnings about constructions that are suspicious
CFLAGS = -Wall

# Names of the executable programs to be built
PROGS = customer_id bill_calculator stock

# Default target: builds all programs
all: $(PROGS)

# Compile the Customer ID program
# Usage: make customer_id
customer_id: customer_id.c
	$(CC) $(CFLAGS) customer_id.c -o customer_id

# Compile the Bill Calculator program
# Usage: make bill_calculator
bill_calculator: bill_calculator.c
	$(CC) $(CFLAGS) bill_calculator.c -o bill_calculator

# Compile the Stock program
# Usage: make stock
stock: stock.c
	$(CC) $(CFLAGS) stock.c -o stock

# Clean up compiled files
# Usage: make clean
# This command removes all compiled executables, useful for cleaning up the directory.
clean:
	rm -f $(PROGS)
