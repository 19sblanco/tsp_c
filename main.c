#include <stdio.h> 
#include <stdlib.h>
#include "lib.c"
#include "test.c"




void tsp_helper(float* distance, int** path, int cc, int fc, int* available_cities, float** distances, float curr_dist) {
    // todo: 
    // impliment this now
    // you still haven't fully finisehd tsp
    // notice you didn't copy the path parameter from the original implimentation

}


/*
distance - changed inside function to shortest path distance
path - changed inside function to the shortest path eg: [4,3,2,1,4]
*/
void tsp(float* distance, int** path, float** distances, int n) {
    // create a list of cities [1,2,...,n]
    // you are now trying to impliment tsp from the python code
    // look out for how you are going to get teh distance nad path
    // from the helper function and then pass on those values to the
    // reutrn values in the parameters (distnace, path)

    

    int* shortest_path = (int*)malloc(sizeof(int) * n);
    int* cities = range(n);

    

    for (int i = 0; i < n; i++) {
        int* cp_ac = cp_int_array(cities, n);
        int* cp = arr_remove(cp_ac, n, i);
        float distance = 0.0;
        int path[n];
        tsp_helper(&distance, &path, i, i, cp, distances, 0);
    }
    


    *distance = 5.0;
    *path = shortest_path;
}


int main() { 
    // run_tests();

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
