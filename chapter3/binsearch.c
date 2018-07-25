#include <stdio.h>
#include <limits.h>
#include "binsearch_data.h"

/* binary search - finds position of x in sorted array v
 * returns -1 if value was not found
 * three branches (two tests) in while */
int binsearch_1(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid-1;
        else if (x > v[mid])
            low = mid+1;
        else    /* found */
            return mid;
    }
    return -1;
}

/* binary search
 * one branch in while; whether to continue in the upper or lower half is
 * determined by computing the sign of x-v[mid] - this might overflow for
 * large values */
int binsearch_2(int x, int v[], int n)
{
    int low, high, mid, sign;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x == v[mid])
            return mid;
        /* sign = if (x-v[mid]) < 0 then 1 else 0
         * 1: x in lower half; 0: x in upper half */
        sign = (int)((unsigned)((int)(x-v[mid])) >> (sizeof(int) * CHAR_BIT - 1));
        low += (1-sign)*(mid-low + 1);
        high += sign*(mid-high - 1);
    }
    return -1;
}

/* Andrwe Tesker's solution
 * (https://clc-wiki.net/wiki/K&R2_solutions:Chapter_3:Exercise_1) 
 * 
 * see also: https://codereview.stackexchange.com/a/6156
 * The original solution might exit early requireing 1 to 2*ceil(log_2(n)+1)
 * comparisons, while this solution always requires ceil(log_2(n)+1) */
int binsearch_3(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (x == v[low]) ? low : -1;
}

int main()
{
    int i, pos1, pos2, pos3;
    for (i = 0; i < 100; ++i) {
        pos1 = binsearch_1(values[i], sample, 1000);
        pos2 = binsearch_2(values[i], sample, 1000);
        pos3 = binsearch_3(values[i], sample, 1000);
        printf("%d %sin sample\t%d\t%d\t%d\n",
                values[i], (pos1 > -1)?(""):("not "), pos1, pos2, pos3);
        /* binsearch_1(values[i], sample, 1000); */
        /* binsearch_2(values[i], sample, 1000); */
    }
    return 0;
}
