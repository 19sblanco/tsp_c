#include <stdio.h> 
#include <stdlib.h>

#include "lib.c"


// todo test remove function with various inputs
void test_remove_1() {
    printf("=== removing 3 ===\n");
    int n = 5;
    int* arr = range(n);
    int* newarr = arr_remove(arr, n, 3);
    print_array(arr, n);
    print_array(newarr, n-1);
    printf("=== ===\n");
}

void test_remove_2() {
    printf("=== removing 1,2 ===\n");
    int n = 5;
    int* arr = range(n);
    int* newarr0 = arr_remove(arr, n, 1);
    int* newarr1 = arr_remove(newarr0, n-1, 2);
    print_array(arr, n);
    print_array(newarr0, n-1);
    print_array(newarr1, n-2);
    printf("=== ===\n");
}

void test_almost_equal() {
    printf("=== almost equal===\n");
    double n0 = 5.0;
    double n1 = 5.001;
    if (almost_equal(n0, n1) == 1) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }

    printf("=== ===\n");
}

void test_add_1() {
    printf("=== adding 3 ===\n");
    int n = 5;
    int* arr = range(n);
    int* newarr = arr_add(arr, n, 3);
    print_array(arr, n);
    print_array(newarr, n+1);
    printf("=== ===\n");
}

void test_cp_int_array_1() {
    printf("=== copy 0 elements ===\n");
    int n = 0;
    int* arr = range(n);
    int* newarr = cp_int_array(arr, n);
    print_array(arr, n);
    print_array(newarr, n);
    printf("=== ===\n");
}

void test_zeros_1() {
    printf("=== 5 element array w/ 0's ===\n");
    int n = 5;
    int* arr = zeros(n);
    print_array(arr, n);
    printf("=== ===\n");

}

void test_equals_1() {
    printf("=== test 2 array equal ===\n");
    int n = 5;
    int* arr1 = range(n);
    int* arr2 = range(n);
    if (arr_equal(arr1, arr2, n) == 1) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}

void test_equals_2() {
    printf("=== test 2 array not equal ===\n");
    int n = 5;
    int* arr1 = range(n);
    int* arr2 = zeros(n);
    if (arr_equal(arr1, arr2, n) == 0) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}

void test_tsp_1() {
    printf("=== tsp1 ===\n");
    int n = 3;
    city* cities = (city*) malloc(sizeof(city) * n);
    cities[0] = make_city(0.0, 0.0);
    cities[1] = make_city(0.0, 3.0);
    cities[2] = make_city(4.0, 0.0);
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    double true_distance = 12.0;
    if (distance == true_distance) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}


void test_tsp_2() {
    printf("=== tsp2 ===\n");
    int n = 4;
    city* cities = (city*) malloc(sizeof(city) * n);
    cities[0] = make_city(0.0, 0.0);
    cities[1] = make_city(0.0, 3.0);
    cities[2] = make_city(4.0, 0.0);
    cities[3] = make_city(0.0, 9.0);
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    double true_distance = 3 + 6 + pow(97, .5) + 4;
    if (distance == true_distance) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}


void test_tsp_3() {
    printf("=== tsp3 ===\n");
    int n = 4;
    city* cities = (city*) malloc(sizeof(city) * n);
    cities[0] = make_city(0.0, 0.0);
    cities[1] = make_city(-1.0, 1.0);
    cities[2] = make_city(1.0, 1.0);
    cities[3] = make_city(0.0, -1.0);
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    double true_distance = pow(2, .5) + 2 + get_distance(cities[3], cities[2]) + 1;
    if (distance == true_distance) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}


void test_tsp_4() {
    printf("=== tsp4 ===\n");
    int n = 3;
    city* cities = (city*) malloc(sizeof(city) * n);
    cities[0] = make_city(0.0, 0.0);
    cities[1] = make_city(0.0, 0.0);
    cities[2] = make_city(0.0, 0.0);
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    double true_distance = 0;
    if (distance == true_distance) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}

void test_tsp_5() {
    printf("=== tsp5 ===\n");
    int n = 5;
    city* cities = (city*) malloc(sizeof(city) * n);
    cities[0] = make_city(0.0, 0.0);
    cities[1] = make_city(-1.0, 2.0);
    cities[2] = make_city(1.0, 4.0);
    cities[3] = make_city(-1.0, 8.0);
    cities[4] = make_city(1.0, 12.0);
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);

    double true_distance = 24.831310;
    if (almost_equal(distance, true_distance) == 1) {
        printf("success!\n");
    }
    else {
        printf("fail!\n");
    }
    printf("=== ===\n");
}

void random_cities_1() {
    printf("=== random cities 1 ===\n");
    int n = 5;
    double threshold = .01;
    int* order = range(n);
    for (int i = 0; i < n; i++) {
        city* cities = random_cities(n, threshold);
        print_cities(cities, order, n);
    }
    printf("=== ===\n");
}


void test_tsp_memory() {

    printf("=== memory stress test ===\n");
    int n = 12;
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
    city c11 = make_city(6.0, 142.0);
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
    cities[11] = c11;
    double** distances = get_distances(cities, n);
    double distance = 0.0;
    int* path = (int*)malloc(sizeof(int) * n);
    tsp(&distance, &path, distances, n);
    printf("sucess!\n");
    printf("=== ===\n");

}


int main() {
    // test_remove_1();
    // test_remove_2();
    // test_almost_equal();
    // test_add_1();
    // test_cp_int_array_1();
    // test_zeros_1();
    // test_equals_1();
    // test_equals_2();
    test_tsp_1();
    test_tsp_2();
    test_tsp_3();
    test_tsp_4();
    test_tsp_5();
    test_tsp_memory();
    // random_cities_1();
}