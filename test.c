#include <unistd.h>
#include <stdio.h>

int main(void)
{

    /* A vulnerable programm */
    void *p = sbrk(1024);

    if (p == (void *)-1) {
        perror("sbrk");
        return 1;
    }

    printf("Address: %p\n", p);
    return 0;
}
