#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "lib.c"


/*
tsp_C:
  tsp written in python
    cities: 12
    time: 808.4938039779663

  tsp written in C (on heap)
    cities: 12
    time: 23.480295
    cities: 13
    time: 265.090176

  tsp written in C (on stack)
    cities: 12
    time: 13.547940
    cities:13
    time: 221.827008

  tsp so that search down a path longer than the current best is haulted
    cities: 12
    time: 0.536989
    cities: 13
    time: 2.537332
    cities: 14
    time: 9.415950 
    cities: 15
    time: 14.350740 
    cities: 16
    time: 110.076049
*/




/*
traveling salesman 
n - number of cities (make sure get cities matches this)
*/
int main() { 


    int n = input_random_cities();
    double threshold = 1.0;

    clock_t start, end;
    start = clock();
    city cities[n];
    random_cities(cities, n, threshold);
    double rdistance = 0.0;
    int rpath[n];
    tsp(&rdistance, rpath, cities, n);
    end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    double distances[n*n];
    get_distances(distances, cities, n);

    printf("=== output ===\n");
    printf("distance: %f\npath: ", rdistance);
    print_cities(cities, rpath, n);
    print_distances(distances, n);
    printf("Time used: %f seconds\n", cpu_time_used);
    
    system("paplay /usr/share/sounds/freedesktop/stereo/complete.oga"); // play a bell noise when program is haulted
    return 0; 
}


