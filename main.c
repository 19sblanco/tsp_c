#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "lib.c"





/*
traveling salesman kick off function
n - number of cities (make sure get cities matches this)
*/

int main() { 
    clock_t start, end;
    start = clock();

    int n = 5;
    city* cities = get_cities5();
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used: %f seconds\n", cpu_time_used);


    printf("====\n");
    printf("distance: %f\npath: ", distance);
    print_cities(cities, path, n);
    print_distances(distances, n);
    return 0; 
}
