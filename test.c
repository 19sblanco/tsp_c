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

int main() {
    test_remove_1();
    test_remove_2();
    test_add_1();
    test_cp_int_array_1();
}