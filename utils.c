#include "utils.h"

const void *fbreak;

void init_break(void) {
    fbreak = sbrk(0);
}

void *mafoc(size_t size) {
    HEAP.hbase = (void*)fbreak;
    void *ptr = sbrk(size);
    if (!ptr) {
        printf("Error occured in sbr()");
        exit(EXIT_FAILURE);
    }
    HEAP.ploc = ptr;
    return HEAP.ploc;
}
