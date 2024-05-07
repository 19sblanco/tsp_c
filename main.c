#include <stdio.h> 
#include <stdlib.h>
#include "lib.c"




void tsp_helper(float* distance, int (*rpath)[], int n, int cc, int fc, int* available_cities, float** distances, float curr_dist, int (*path)[], int depth) {
    // todo: 
    // impliment this now
    // you still haven't fully finisehd tsp
    // you are trying to figure out how to handle the return values of tsp_helper
    // right now it manipulates the d and p variables
    // how can you manipulate these in a way that you can update them based on the shortest so far route

    int* cp_p = cp_int_array(*path, depth);
    int* cp_path = arr_add(cp_p, depth, cc);
    int ac_len = n-(depth+1);

    for (int i = 0; i < ac_len; i++) {
        int ac = available_cities[i];
        int* cp_a = cp_int_array(available_cities, ac_len);
        int* cp_ac = arr_remove(cp_a, ac_len, ac);
        float new_dist = curr_dist + distances[cc][ac];
        float d = 99999.0;
        int p[n];
        tsp_helper(&d, &p, n, ac, fc, cp_ac, distances, new_dist, cp_path, ++depth);


    }

    *distance = 10;
    (*rpath)[0] = 5;
    (*rpath)[1] = 5;
    (*rpath)[2] = 5;
    (*rpath)[3] = 5;
    (*rpath)[4] = 5;
}


/*
distance - changed inside function to shortest path distance
path - changed inside function to the shortest path eg: [4,3,2,1,4]
*/
void tsp(float* distance, int** path, float** distances, int n) {
    int* shortest_path = (int*)malloc(sizeof(int) * n);
    int* cities = range(n);
    float curr_dist = 0.0;
    int depth = 0;
    int arr[0];

    for (int i = 0; i < n; i++) {
        int* cp_ac = cp_int_array(cities, n);
        int* cp = arr_remove(cp_ac, n, i);
        float distance = 0.0;
        int path[n];
        tsp_helper(&distance, &path, n, i, i, cp, distances, curr_dist, &arr, depth);
        // printf("%f\n", distance);
        // print_array(path, n);
    }
    

    exit(0);
    *distance = 5.0;
    *path = shortest_path;
}


int main() { 
    int n = 5;
    city* cities = get_cities(n);
    float** distances = get_distances(cities, n);
    float distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    // printf("%f\n", distance);
    // print_array(path, n);
    // print_distances(distances, n);





    return 0; 
}
