#include <stdio.h> 
#include <stdlib.h>
#include "lib.c"






int main() { 
    int n = 3;
    city* cities = get_cities3();
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    printf("====\n");
    printf("distance: %f\npath: ", distance);
    print_array(path, n);
    print_distances(distances, n);





    return 0; 
}
