
#include <string.h>
#include "rng.h"


#if defined(__APPLE__)

#include <sys/random.h>

#endif

int randombytes(unsigned char *x, unsigned long long xlen) {
#if defined(__APPLE__)
    unsigned long long tail = xlen;
    unsigned long long multiplicator = 0;
    while (tail != 0) {
        getentropy(x + multiplicator * 256, tail > 256 ? 256 : tail);
        multiplicator++;
        tail -= tail > 256 ? 256 : tail;
    }
    return xlen;
#endif
    memset(x, 0, xlen);
    return 0;
}





