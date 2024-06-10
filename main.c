#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "lib.c"


/*

be able to input cities (brain storm potential inputs)
    * file input
     
tsp_C:
  tsp written in python
    cities: 12
    time: 808.4938039779663

  tsp written in C
    cities: 12
    time: 23.480295
    cities: 13
    time: 265.090176


*/




/*
traveling salesman 
n - number of cities (make sure get cities matches this)
*/
int main() { 
    int n = input_random_cities();
    double threshold = 1.0;

    clock_t start, end;

    /*
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    city* cities = random_cities(n, threshold);
    double** distances = get_distances(cities, n);
    // tsp(&distance, &path, distances, n);
    */

    start = clock();
    city* cities = random_cities(n, threshold);
    double rdistance = 0.0;
    int rpath[n];
    tsp(&rdistance, rpath, cities, n);
    end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*
    void print_cities(city* cities, int* order, int n) {
        int idx;
        for (int i = 0; i < n; i++) {
            idx = order[i];
            city c = cities[idx];
            printf("(%f, %f) -> ", c.x, c.y);
        }
        printf("(%f, %f) \n", cities[order[0]].x, cities[order[0]].y);
    }
    */

    double** distances = get_distances(cities, n);
    printf("=== output ===\n");
    printf("distance: %f\npath: ", rdistance);
    // print_cities(cities, rpath, n);
    print_distances(distances, n);
    printf("Time used: %f seconds\n", cpu_time_used);
    return 0; 
}

