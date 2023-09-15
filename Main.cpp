#include "Sort.h"
const int array_size = 15;

int main() {
    int a[] = {1, 3, 2, 77, 15, 22, 22, 22, 22};
    //printf("%d", sizeof(a) / sizeof(a[0]));
    //a[1] = 228;
    //gen_arr_int(a, array_size, -2, 10);
    //print_int_arr(a, sizeof(a) / sizeof(a[0]));
    quick_sort_int(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    print_int_arr(a, sizeof(a) / sizeof(a[0]));
}
