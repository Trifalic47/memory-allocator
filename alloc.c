#include "utils.h"

int main()
{
    init_break(); // Must call to initialize BREAK
    int *numbers = (int*)mafoc(2001*sizeof(int));
    numbers[2000] = 10;
    return EXIT_SUCCESS;
}

