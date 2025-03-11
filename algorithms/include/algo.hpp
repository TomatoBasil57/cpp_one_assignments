#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"

inline long fibonacci(const int n)
{
    int nth_term = 0, nth_minus_1 = 1, nth_minus_2 = 0;

    if (n == 0) {return 0;}
    if (n == 1) {return 1;}

    for (int i = 2; i <= n; i++)
    {
        nth_term = nth_minus_2 + nth_minus_1;
        nth_minus_2 = nth_minus_1;
        nth_minus_1 = nth_term;
    }

    return nth_term;
}

inline long linear_search(Array const *a, const int target)
{
    for (unsigned int i = 0; i < a->len; i++)
    {
        if (a->data[i] == target)
        {
            return i;
        }
    }

    return -1;
}

inline long factorial(const int n)
{
    int nth_term = 1; // 0! = 1

    for (int i = 1; i <= n; i++)
    {
        nth_term *= i;
    }

    return nth_term;
}


#endif // ALGO_H_
