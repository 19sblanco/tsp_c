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

/*
test library functions
*/

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
test library functions
*/


/*
remove an item from an array where n is the size of original
*/
void _remove(int* original, int* new, int item, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (original[i] == item) {
            continue;
        }
        else {
            new[j] = original[i];
            j++;
        }
    }
}

/*
add an item to an array where n is the size of original
*/
void _add(int* original, int* new, int item, int n) {
    int i;
    for (i = 0; i < n; i++) {
        new[i] = original[i];
    }
    new[i] = item;
}

/*
copy an array of size n
*/
void _copy(int* original, int* new, int n) {
    for (int i = 0; i < n; i++) {
        new[i] = original[i];
    }
}

/*
//////////////////
todo: start on tests (check error messages when making)
//////////////////
*/


/*
given an array make its elements 0-(n-1)
*/
void _range(int* arr, int n){
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}


/*
*/
void tsp_helper(double** distances, double* rdistance, int* rpath, double curr_distance, int* curr_path, int cc, int fc, int* avail_cities, int n, int depth) {

   int ac_len = n-(depth+1);
   if (ac_len == 0) {
       *rdistance = curr_distance + distances[cc][fc];
       _copy(curr_path, rpath, n);
       return;
   }

   double s_d_sofar = -1.0;
   int s_p_sofar[n];
   
   for (int i = 0; i < ac_len; i++) {
      int ac = avail_cities[i];
      double new_dist = curr_distance + distances[cc][ac];
      int new_ac[ac_len-1];
      _remove(avail_cities, new_ac, ac, ac_len);
      int new_path[depth+1];
      _add(curr_path, new_path, ac, depth);
      double best_distance;
      int best_path[n];
      tsp_helper(distances, &best_distance, best_path, new_dist, new_path, ac, fc, new_ac, n, depth+1);
      if ((s_d_sofar == -1.0) || (best_distance < s_d_sofar)) {
          s_d_sofar = best_distance;
          _copy(best_path, s_p_sofar, n);
      }
   }
   *rdistance = s_d_sofar;
   _copy(s_p_sofar, rpath, n);
}


/*
void tsp_helper(double** distances, double* rdistance, int**rpath, double distance, int* curr_path, int cc, int* avail_cities, int n, int depth) {
*/
void tsp(double* distance, int* path, city* cities, int n) {
    double** distances = get_distances(cities, n);


    int c[n];
    _range(c, n);
    int avail_cities[n-1];
    _remove(c, avail_cities, 0, n);
    int path_so_far[n];

    // used range because we only care about having the
    // 0th index item of path_so_far to be 0
    _range(path_so_far, n); 
    double rdistance = 0.0;
    int rpath[n];
    tsp_helper(distances, &rdistance, rpath, 0, path_so_far, 0, 0, avail_cities, n, 0);
    *distance = rdistance;
    _copy(rpath, path, n);
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
