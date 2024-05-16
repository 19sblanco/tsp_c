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
     
*/




/*
traveling salesman 
n - number of cities (make sure get cities matches this)
*/
int main() { 
    int n = input_random_cities();
    double threshold = 1.0;

    clock_t start, end;

    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    city* cities = random_cities(n, threshold);
    double** distances = get_distances(cities, n);

    start = clock();
    tsp(&distance, &path, distances, n);
    end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used: %f seconds\n", cpu_time_used);


    printf("=== output ===\n");
    printf("distance: %f\npath: ", distance);
    print_cities(cities, path, n);
    print_distances(distances, n);
    return 0; 
}
