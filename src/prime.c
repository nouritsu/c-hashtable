#include "./prime.h"

#include <math.h>

int is_prime(const int x) {
    if (x < 2) {
        return PR_UNDEFINED;
    }
    if (x < 4) {
        return PR_ISPRIME;
    }
    if ((x % 2) == 0) {
        return PR_NOTPRIME;
    }
    for (int i = 3; i <= floor(sqrt((double)x)); i += 2) {
        if ((x % i) == 0) {
            return PR_NOTPRIME;
        }
    }
    return PR_ISPRIME;
}

int next_prime(int x) {
    while (is_prime(x) != 1) {
        x++;
    }
    return x;
}
