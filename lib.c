#include <math.h>
#include <time.h>


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
    city c10 = make_city(100.0, 42.0);
    // city c11 = make_city(6.0, 142.0);
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
    cities[10] = c10;
    // cities[11] = c11;
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

gets the path and distance of the shortest path
*/
void tsp_helper(double* rdistance, int** rpath, int n, int cc, int fc, int* available_cities, double** distances, double curr_dist, int* path, int depth) {
    int* cp_path = arr_add(path, depth, cc);
    int ac_len = n-(depth+1);

    double s_d_sofar = -1.0;
    int* s_p_sofar = zeros(0);

    for (int i = 0; i < ac_len; i++) {
        int ac = available_cities[i];
        int* cp_ac = arr_remove(available_cities, ac_len, ac);
        double new_dist = curr_dist + distances[cc][ac];
        double d = 0.0;
        int* p = zeros(0);
        tsp_helper(&d, &p, n, ac, fc, cp_ac, distances, new_dist, cp_path, depth+1);
        if ((s_d_sofar == -1.0) || (d < s_d_sofar)) {
            s_d_sofar = d;
            free(s_p_sofar);
            s_p_sofar = cp_int_array(p, n);
        }
        free(p);
        free(cp_ac);
    }
    free(*rpath);
    if (ac_len < 1) {
        *rdistance = curr_dist + distances[cc][fc];
        *rpath = cp_int_array(cp_path, n);
    }
    else {
        *rdistance = s_d_sofar;
        *rpath = cp_int_array(s_p_sofar, n);
    }
    free(s_p_sofar);
    free(cp_path);
}


/*
distance - changed inside function to shortest path distance
path - changed inside function to the shortest path eg: [4,3,2,1,4]
*/
void tsp(double* shortest_distance, int** path, double** distances, int n) {
    int* shortest_path = (int*)malloc(sizeof(int) * n);

    double r_distance = 0.0;
    int* r_path = zeros(0);
    int first_city = 0;
    int* cities = range(n);
    int* avail_cities = arr_remove(cities, n, first_city);
    int* path_so_far = zeros(0);

    tsp_helper(&r_distance, &r_path, n, first_city, first_city, avail_cities, distances, 0,  path_so_far, 0);

    *shortest_distance = r_distance;
    *path = cp_int_array(shortest_path, n);

    free(shortest_path);
    free(r_path);
    free(cities);
    free(avail_cities);
    free(path_so_far);
}

/*
check whether or not a city is withing the threshold distance of
the other cities
*/
int within_range(city* cities, int n, city c, double threshold) {
    for (int i = 0; i < n; i++) {
        double dist = get_distance(c, cities[i]);
        if (dist < threshold) {
            return 1;
        }
    }
    return 0;
}

city* random_cities(int n, double threshold) {
    srand(time(NULL));
    int x, y, in_range;
    city c;
    city* cities = (city*) malloc(sizeof(city) * n);
    for (int i = 0; i < n; i++) {
        while (1) {
            x = rand();
            y = rand();
            c = make_city(x, y);
            in_range = within_range(cities, i, c, threshold);
            if (in_range == 0) {
                break;
            }
        }
        cities[i] = c;
    }
    return cities;
}

int input_random_cities() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    return number;
}
