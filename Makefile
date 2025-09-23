# Makefile for Data Structures and Algorithms in C
# Compilation instructions for all programs

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Programs
PROGRAMS = arrays linked_lists stack queue trees graphs searching sorting dynamic_programming

# Default target
all: $(PROGRAMS)

# Individual targets
arrays: arrays.c
	$(CC) $(CFLAGS) -o $@ $<

linked_lists: linked_lists.c
	$(CC) $(CFLAGS) -o $@ $<

stack: stack.c
	$(CC) $(CFLAGS) -o $@ $<

queue: queue.c
	$(CC) $(CFLAGS) -o $@ $<

trees: trees.c
	$(CC) $(CFLAGS) -o $@ $<

graphs: graphs.c
	$(CC) $(CFLAGS) -o $@ $<

searching: searching.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

sorting: sorting.c
	$(CC) $(CFLAGS) -o $@ $<

dynamic_programming: dynamic_programming.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(PROGRAMS)

# Debug versions
debug: CFLAGS += -g -DDEBUG
debug: $(PROGRAMS)

# Test target to verify compilation
test: all
	@echo "All programs compiled successfully!"
	@echo "Available programs: $(PROGRAMS)"

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Compile all programs"
	@echo "  clean            - Remove all compiled programs"
	@echo "  debug            - Compile with debug symbols"
	@echo "  test             - Verify compilation"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Individual programs:"
	@echo "  $(PROGRAMS)"
	@echo ""
	@echo "Usage examples:"
	@echo "  make all         - Compile everything"
	@echo "  make arrays      - Compile only arrays program"
	@echo "  make clean       - Clean compiled files"

.PHONY: all clean debug test help