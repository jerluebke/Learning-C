#include <stdio.h>
#include "shellsort.h"

/* shellsort: bring v into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, tmp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; ++i)
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
                tmp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = tmp;
            }
}

int main()
{
    /* shellsort(sample2, 1000); */
    shellsort(sample1, 100);
    int i;
    for (i = 0; i < 100; ++i)
        printf("%d%c", sample1[i], (i+1)%5 ? '\t' : '\n');

    return 0;
}
