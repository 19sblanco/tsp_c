#include <stdio.h> 
#include <stdlib.h>
#include "lib.c"




/*
cp_path: a path array that addeds the current city throughout recursion
ac_len: length of the available_cities array
s_p_sofar[n]: "shortest_path_sofar"
s_d_sofar: "shorest_distance_sofar"
*/
void tsp_helper(float* distance, int** rpath, int n, int cc, int fc, int* available_cities, float** distances, float curr_dist, int** path, int depth) {
    int* cp_path = arr_add(*path, depth, cc);
    int ac_len = n-(depth+1);

    int* s_p_sofar = zeros(n);
    float s_d_sofar = -1.0;

    for (int i = 0; i < ac_len; i++) {
        int ac = available_cities[i];
        int* cp_ac = arr_remove(available_cities, ac_len, ac);
        float new_dist = curr_dist + distances[cc][ac];
        float d = 0.0;
        int* p = zeros(n);
        tsp_helper(&d, &p, n, ac, fc, cp_ac, distances, new_dist, &cp_path, ++depth);
        if ((s_d_sofar == -1.0) || d < s_d_sofar) {
            s_d_sofar = d;
            s_p_sofar = cp_int_array(p, n);
        }
    }
    if (ac_len < 1) {
        s_d_sofar = curr_dist + distances[cc][fc];
        s_p_sofar = cp_path;
    }

    *distance = s_d_sofar;
    *rpath = s_p_sofar;
}


/*
distance - changed inside function to shortest path distance
path - changed inside function to the shortest path eg: [4,3,2,1,4]
*/
void tsp(float* distance, int** path, float** distances, int n) {
    int* shortest_path = (int*)malloc(sizeof(int) * n);
    float shortest_distance = -1.0;

    int* cities = range(n);
    float curr_dist = 0.0;
    int depth = 0;
    int* arr = zeros(0);

    for (int i = 0; i < n; i++) {
        int* cp_ac = cp_int_array(cities, n);
        int* cp = arr_remove(cp_ac, n, i);
        float distance = 0.0;
        int* path = zeros(n);
        tsp_helper(&distance, &path, n, i, i, cp, distances, curr_dist, &arr, depth);
        printf("%f\n", distance);
        print_array(path, n);
        if ((shortest_distance == -1) || (distance < shortest_distance)) {
            shortest_distance = distance;
            shortest_path = cp_int_array(path, n);
        }
    }
    *distance = shortest_distance;
    *path = cp_int_array(shortest_path, n);

}


int main() { 
    int n = 3;
    city* cities = get_cities3();
    float** distances = get_distances(cities, n);
    float distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    printf("====\n");
    printf("%f\n", distance);
    print_array(path, n);
    // print_distances(distances, n);





    return 0; 
}
