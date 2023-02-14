#include <stdio.h>
#include <time.h>

#define SIZE 99999
int matrices[SIZE][SIZE];

void main()
{
    // Counters
    int i, j;
    // Timings
    clock_t start, end;
    double d = 0.0;

    start = clock();
    // Iterate on rows
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            matrices[i][j] = matrices[i][j] + (matrices[i][j] * matrices[i][j]);

    // Output timings
    end = clock();
    d = (double)(end - start) / CLOCKS_PER_SEC;
    printf("row major run time is %lf milliseconds\n", 1000 * d);

    start = clock();
    // Iterate on columns
    for (j = 0; j < SIZE; j++)
        for (i = 0; i < SIZE; i++)
            matrices[i][j] = matrices[i][j] + (matrices[i][j] * matrices[i][j]);

    end = clock();
    d = (double)(end - start) / CLOCKS_PER_SEC;
    printf("column major run time is %lf milliseconds\n", 1000 * d);
}
