#include "Sort.h"

int main() {
    int a[10] = {9, 3, 2, 5, 8, 1, 0, 6, 7, 4};

    selection_sort_int(a, sizeof(a) / sizeof(a[0]));

    print_int_arr(a, sizeof(a) / sizeof(a[0]));
}
