#include "Sort.h"

static void swap_int(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

static int find_min(int data[], int size_) {
    int min_ptr = 0;
    int min_ = 999;

    for(int i = 0; i < size_; i++) {
        if(min_ >= data[i]) {
            min_ptr = i;
            min_ = data[i];
        }
    }
    return min_ptr;
}

void bubble_sort_int(int data[], int size_) {

    for(int n = 0; n < size_; n++) {
        int is_swap = 0;
        for(int i = 0; i < size_ - 1 - n; i++)
            if(data[i] > data[i + 1]) {
                swap_int(&data[i], &data[i + 1]);
                is_swap = 1;
            }
        if(is_swap == 0)
            break;
    }
}

void selection_sort_int(int data[], int size_) {
    int s = size_;

    for(int i = 0; i < size_; i++) {
        int ptr_min = i + find_min(&*(data + i), s);

        swap_int(&data[i], &data[ptr_min]);
        s--;
    }
}

void print_int_arr(int* a, int nums) {
    for(int i = 0; i < nums; i++)
        printf("%d ", a[i]);
    putchar('\n');
}

static int partition_(int data[], int left, int right) {
    //int pivot = data[(left + right) / 2]; - mid pivot
    int pivot = data[rand() % (right - left)];  // - rand pivot

    /*printf("pivot = %d\n", pivot);
    printf("left = %d right = %d\n", left, right); to output iteration info
*/

    int i = left, j = right;

    while(true) {
        while(data[i] < pivot) i = i + 1;
        while(data[j] > pivot) j = j - 1;
        if(i >= j) return j;
        /*printf("to swap 1 - %d, 2 - %d\n", data[i], data[j]);
        print_int_arr(data, 10);*/
        swap_int(&data[i++], &data[j--]);
    }
}


//int iteration = 0;

void quick_sort_int(int data[], int left, int right) {

    if(left < right && right - left > 1) {
        //print_int_arr(data, 10);
        int p = partition_(data, left, right);
        //iteration++;
        /*if(iteration == 100)     to avoid inf loop
            _Exit (EXIT_SUCCESS);*/
        quick_sort_int(data, left, p);
        quick_sort_int(data, p, right);
    }
}
