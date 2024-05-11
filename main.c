#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "lib.c"


/*

todo: be able to generate random cities (reject ones that are too close)
    * work in lib file, ran in test
be able to input cities (brain storm potential inputs)
    * file input
    * manually typing it in
     
     
problem: with 12 cities there is too much memory being used
two solutions:
    1 free memory that is no longer used in tsp helper
    2 make a memory efficient version of svm (more computation less caching)
*/




/*
traveling salesman kick off function
n - number of cities (make sure get cities matches this)
*/
int main() { 
    clock_t start, end;
    start = clock();

    int n = 11;
    city* cities = get_cities5(n);
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
