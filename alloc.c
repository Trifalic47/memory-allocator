#include "utils.h"

int main()
{
    int *ages = (int*)mafoc(5*sizeof(int));
    // mafree(&ages);

    return EXIT_SUCCESS;
}

