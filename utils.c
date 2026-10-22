#include "utils.h"

const void *fbreak;

void init_func(void) {
    fbreak = sbrk(0);
    HEAP.hbase = (void*)fbreak;
    free_db.total_entries = 0;
    heap_db.total_entries = 0;
}

void *mafoc(size_t size) {
    struct heap_entry entry;

    void *ptr = sbrk(size);
    if (ptr == (void*)-1) {
        printf("Error occured in sbr()");
        exit(EXIT_FAILURE);
    }
    entry.addr = &ptr;
    entry.size = size;
    entry.isfree = false;
    HEAP.ploc = ptr;
    return HEAP.ploc;
}


/*
void mafree(void *ptr) {
    struct free_entry entry;
    entry.addr = &ptr;
    entry.size = sizeof(ptr);
    printf("address: %p \t size: %ld\n",ptr,sizeof(ptr));

    free_db.entries[free_db.total_entries] = &entry;
    free_db.total_entries++;
}
*/
