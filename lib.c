#include <math.h>


typedef struct {
    double x;
    double y;
} city;

city make_city(double x, double y) {
    city c;
    c.x = x;
    c.y = y;
    return c;
}


city* get_cities5(int n) {
    city* cities = (city*) malloc(sizeof(city) * n);
    city c0 = make_city(0.0, 0.0);
    city c1 = make_city(-1.0, 2.0);
    city c2 = make_city(1.0, 4.0);
    city c3 = make_city(-1.0, 8.0);
    city c4 = make_city(1.0, 12.0);
    city c5 = make_city(100.0, 12.0);
    city c6 = make_city(12.0, 12.0);
    city c7 = make_city(-13.0, -13.0);
    city c8 = make_city(-130.0, -13.0);
    city c9 = make_city(690.0, 42.0);
    cities[0] = c0;
    cities[1] = c1;
    cities[2] = c2;
    cities[3] = c3;
    cities[4] = c4;
    cities[5] = c5;
    cities[6] = c6;
    cities[7] = c7;
    cities[8] = c8;
    cities[9] = c9;
    return cities;
}

city* get_cities3() {
    city* cities = (city*) malloc(sizeof(city) * 3);
    city c0 = make_city(0.0, 0.0);
    city c1 = make_city(-1.0, 2.0);
    city c2 = make_city(1.0, 4.0);
    cities[0] = c0;
    cities[1] = c1;
    cities[2] = c2;
    return cities;
}

void print_cities(city* cities, int* order, int n) {
    int idx;
    for (int i = 0; i < n; i++) {
        idx = order[i];
        city c = cities[idx];
        printf("(%f, %f) -> ", c.x, c.y);
    }
    printf("(%f, %f) \n", cities[order[0]].x, cities[order[0]].y);

}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

double get_distance(city c1, city c2) {
    return pow( pow(c1.x-c2.x, 2) + pow(c1.y-c2.y, 2), .5);
}


double** get_distances(city* cities, int n) {
    double** distances = (double**) malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        double* row = (double*) malloc(sizeof(double) * n);
        distances[i] = row;
        for (int j = 0; j < n; j++) {
            double dist = get_distance(cities[i], cities[j]);
            row[j] = dist;
        }
    }
    return distances;
}

void print_distances(double** distances, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", distances[i][j]);
        }
        printf("\n\n");
    }
}

int* range(int n){
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

int* zeros(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    return arr;

}

int* cp_int_array(int* arr, int n) {
    int* cparr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cparr[i] = arr[i];
    }
    return cparr;
}

int* arr_remove(int* arr, int n, int item) {
    int* newarr = (int*)malloc(sizeof(int) * (n-1));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            continue;
        }
        newarr[j] = arr[i];
        j++;
    }
    return newarr;
}

int* arr_add(int* arr, int n, int item) {
    int* newarr = (int*)malloc(sizeof(int) * (n+1));
    for (int i = 0; i < n; i++) {
        newarr[i] = arr[i];
    }
    newarr[n] = item;
    return newarr;
}

int arr_equal(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

double rando() {
    double rand_double = (double)rand() / RAND_MAX;
    return rand_double;
}

int almost_equal(double a, double b) {
    double threshold = .1;
    if ((a > (b-threshold)) && (a < (b+threshold))) {
        return 1;
    }
    else return 0;
}

/*
cp_path: a path array that addeds the current city throughout recursion
ac_len: length of the available_cities array
s_p_sofar[n]: "shortest_path_sofar"
s_d_sofar: "shorest_distance_sofar"
*/
void tsp_helper(double* distance, int** rpath, int n, int cc, int fc, int* available_cities, double** distances, double curr_dist, int* path, int depth) {
    int* cp_path = arr_add(path, depth, cc);
    int ac_len = n-(depth+1);

    double s_d_sofar = -1.0;
    int* s_p_sofar = zeros(n);

    for (int i = 0; i < ac_len; i++) {
        int ac = available_cities[i];
        int* cp_ac = arr_remove(available_cities, ac_len, ac);
        double new_dist = curr_dist + distances[cc][ac];
        double d = 0.0;
        int* p = zeros(n);
        tsp_helper(&d, &p, n, ac, fc, cp_ac, distances, new_dist, cp_path, depth+1);
        if ((s_d_sofar == -1.0) || (d < s_d_sofar)) {
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
void tsp(double* distance, int** path, double** distances, int n) {
    int* shortest_path = (int*)malloc(sizeof(int) * n);
    double shortest_distance = -1.0;

    int* cities = range(n);
    double curr_dist = 0.0;
    int depth = 0;
    int* arr = zeros(0);

    for (int i = 0; i < n; i++) {
        int* cp = arr_remove(cities, n, i);
        double distance = 0.0;
        int* path = zeros(n);
        tsp_helper(&distance, &path, n, i, i, cp, distances, curr_dist, arr, depth);
        if ((shortest_distance == -1.0) || (distance < shortest_distance)) {
            shortest_distance = distance;
            shortest_path = cp_int_array(path, n);
        }
    }
    *distance = shortest_distance;
    *path = cp_int_array(shortest_path, n);

}