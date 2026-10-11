#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

extern const void *fbreak; // the value of the first sbrk(0) [where the heap ends]
void init_break(void);


/* 'heap' struct contains all the information about the 'Heap' */
typedef struct {
    void *hbase; /* Means heap-base (the point where heap starts and stack ends [break]) */
    void *ploc; /* Points to the last address used in the heap */
    bool isfree; // contains true/false.True if whole heap is freed
} heap;

extern heap HEAP;

void *mafoc(size_t size);
#endif

