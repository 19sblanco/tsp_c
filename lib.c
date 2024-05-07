#include <math.h>


typedef struct {
    float x;
    float y;
} city;

city make_city(float x, float y) {
    city c;
    c.x = x;
    c.y = y;
    return c;
}


city* get_cities5() {
    city* cities = (city*) malloc(sizeof(city) * 5);
    city c0 = make_city(0.0, 0.0);
    city c1 = make_city(-1.0, 2.0);
    city c2 = make_city(1.0, 4.0);
    city c3 = make_city(-1.0, 8.0);
    city c4 = make_city(1.0, 12.0);
    cities[0] = c0;
    cities[1] = c1;
    cities[2] = c2;
    cities[3] = c3;
    cities[4] = c4;
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

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void print_cities(city* cities, int n) {
    for (int i = 0; i < n; i++) {
        float x = cities[i].x;
        float y = cities[i].y;
        printf("(%f, %f)-> ", x, y);
    }
    printf("\n");
}

float** get_distances(city* cities, int n) {
    float** distances = (float**) malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) {
        float* row = (float*) malloc(sizeof(float) * n);
        distances[i] = row;
        for (int j = 0; j < n; j++) {
            city fc = cities[i];
            city tc = cities[j];
            float distance = pow( pow(fc.x-tc.x, 2) + pow(fc.y-tc.y, 2), .5);
            row[j] = distance;
        }
    }
    return distances;
}

void print_distances(float** distances, int n) {
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
