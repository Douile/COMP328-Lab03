/*
 * Written by Dr Maryam Abo Tabik
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Test different optmization options by changing m & n values, see how that effects the program performance
int m = 5;
int n = 5;

void assign(int** arr, int m, int n)
{
    // Assign random values to the 2D array
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            arr[y][x] = rand();
        }
    }
}

void _print(int** arr, int m, int n)
{
    // Print the 2D array
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void _free(int** arr, int m, int n)
{
    // Free the memory space locating the 2D array
    int i;
    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
}

void _add(int** arr1, int** arr2, int** arr3, int m, int n)
{
    // Add two 2D arrays and store the results in a third one
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            arr3[y][x] = arr1[y][x] + arr2[y][x];
        }
    }
}

int main(int argc, char** argv)
{
    if (argc == 3) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    printf("m=%d n=%d\n", m, n);

    int r, i;
    clock_t start_time, end_time;

    // dynamically create an array of pointers of size `m`
    int** arr1 = (int**)malloc(m * sizeof(int*));
    int** arr2 = (int**)malloc(m * sizeof(int*));
    int** arr3 = (int**)malloc(m * sizeof(int*));

    // dynamically allocate memory of size `n` for each row
    for (r = 0; r < m; r++) {
        arr1[r] = (int*)malloc(n * sizeof(int));
        arr2[r] = (int*)malloc(n * sizeof(int));
        arr3[r] = (int*)malloc(n * sizeof(int));
    }

    // assign the arrays with random values
    assign(arr1, m, n);
    assign(arr2, m, n);
    assign(arr3, m, n);

    // arr3 = arr1 + arr2
    // add timer to count processing time for the _add function
    start_time = clock();
    _add(arr1, arr2, arr3, m, n);
    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("_add took %fms\n", 1000.0 * (float)total_time);

    // print 2D array
    printf("First array:\n");
    _print(arr1, m, n);
    printf("\n Second Array: \n");
    _print(arr2, m, n);
    printf("\n Third Array: \n");
    _print(arr3, m, n);

    // deallocate memory
    _free(arr1, m, n);
    _free(arr2, m, n);
    _free(arr3, m, n);

    return 0;
}
