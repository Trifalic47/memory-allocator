#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

#define FREE_DB_CAPACITY 1024
#define HEAP_DB_CAPACITY 1024

extern const void *fbreak; // the value of the first sbrk(0) [where the heap ends]
void init_func(void) __attribute__((constructor)); // GCC only

/* 'heap' struct contains all the information about the 'Heap' */
struct heap {
    void *hbase; /* Means heap-base (the point where heap starts and stack ends [break]) */
    void *ploc; /* Points to the last address used in the heap */
    bool isfree; // contains true/false.True if whole heap is freed
};

struct heap_entry {
    void *addr;
    size_t size;
    bool isfree;
};

struct heap_db {
    struct heap_entries *h_entries[HEAP_DB_CAPACITY];
    int total_entries;
};

struct free_entry {
    void *addr;
    size_t size;
};

struct free_db{
    struct free_entries *entries[FREE_DB_CAPACITY];
    int total_entries;
};

static struct heap_db heap_db;

static struct heap HEAP;
static struct free_db free_db;

void *mafoc(size_t size);
void mafree(void *ptr);
#endif
