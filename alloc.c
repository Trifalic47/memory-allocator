#include "utils.h"

int main()
{
    /* TESTING: Allocating memory in heap for 5 uint8_t integers */
    uint8_t *ages = (uint8_t*)mafoc(5*sizeof(uint8_t));

    return EXIT_SUCCESS;
}

