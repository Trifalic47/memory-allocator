#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

#define FREE_DB_CAPACITY 1024

extern const void *fbreak; // the value of the first sbrk(0) [where the heap ends]
void init_break(void) __attribute__((constructor)); // GCC only

/* 'heap' struct contains all the information about the 'Heap' */
struct heap {
    void *hbase; /* Means heap-base (the point where heap starts and stack ends [break]) */
    void *ploc; /* Points to the last address used in the heap */
    bool isfree; // contains true/false.True if whole heap is freed
};

struct free_entries {
    void *addr;
    size_t size;
};

struct free_db{
    struct free_entries entries[FREE_DB_CAPACITY];
    int total_entries;
};

extern struct heap HEAP;

void *mafoc(size_t size);
void mafree(void *ptr);
#endif
