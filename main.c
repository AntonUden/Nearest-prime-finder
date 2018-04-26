#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main() {
    while(true) {
        int num, nitems;
        fflush(stdin);
        printf("Input a number: ");
        nitems = scanf("%d", &num);
        if (nitems == EOF || nitems == 0) {
            printf("Input error\n");
        } else {
            printf("Nearest prime to %i is %i\n", num, getNearest(num));
        }
    }
    return 0;
}

int isPrime(int n){
    int i;

    if (n==2)
        return 1;
    if (n%2==0)
        return 0;
    if (n < 2)
        return 0;
    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}

int getNearest(int n) {
    if(isPrime(n))
        return n;
    if(n < 2)
        return 2;
    for(int i = 0; i < INT_MAX; i++) {
        if(isPrime(n + i)) {
            return (n + i);
        }
        if(n - i > 1) {
            if(isPrime(n - i)) {
                return (n - i);
            }
        }
    }
}
