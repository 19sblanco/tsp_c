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





int main() {
    test_remove_1();
    test_remove_2();
    test_almost_equal();
    test_add_1();
    test_cp_int_array_1();
    test_zeros_1();
    test_equals_1();
    test_equals_2();
    test_tsp_1();
    test_tsp_2();
    test_tsp_3();
    test_tsp_4();
    test_tsp_5();
}