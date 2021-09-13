#include "nth_prime.h"
#include <stdlib.h>
#include <stdio.h>

uint32_t nth(uint32_t n)
{
    unsigned int* currentPrime = calloc(10, sizeof(int));
    unsigned int* lastPrimes = calloc(10, sizeof(int));
    unsigned int i = 0;

    if(n == 0)
    {
        return 0;
    }    
    else if(n == 1)
    {
        return 2;
    }
    else if(n == 2)
    {
        return 3;
    }
    else
    {
        lastPrimes[i] = 2;
        lastPrimes[i + 1] = 3;
        i++;
    }

    unsigned int possiblePrime = lastPrimes[i] + 2;
    unsigned int temp = 2;

    while(temp < n)
    {
        while(isPrime(lastPrimes, possiblePrime, i) != 0)
        {
            possiblePrime += 2;
        }
        i++;
        lastPrimes[i] = possiblePrime;
        currentPrime[0] = possiblePrime;
        temp++;
    }
    return currentPrime[0];
}

uint32_t isPrime(unsigned int *lastPrime, unsigned int possiblePrime, unsigned int numPrimes)
{
    while(numPrimes > 0){
        if(possiblePrime % lastPrime[numPrimes] == 0){
            return 1;                       
        }
        numPrimes--;
    }
    return 0;
} 
