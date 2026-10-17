#include "utils.h"

const void *fbreak;
struct heap HEAP;

void init_break(void) {
    fbreak = sbrk(0);
}

void *mafoc(size_t size) {
    HEAP.hbase = (void *)fbreak;
    void *ptr = sbrk(size);
    if (ptr == (void*)-1) {
        printf("Error occured in sbr()");
        exit(EXIT_FAILURE);
    }
    HEAP.ploc = ptr;
    return HEAP.ploc;
}

void mafree(void *ptr) {

}
