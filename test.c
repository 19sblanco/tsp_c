#include <stdio.h> 
#include <stdlib.h>


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

void run_tests() {
    test_remove_1();
    test_remove_2();
}