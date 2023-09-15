#include "Sort.h"


void gen_arr_int(int* arr, int size_, int min_value, int max_value) {
    for(int i = 0; i < size_; i++)
        arr[i] = min_value + (rand() % (max_value - min_value + 1));
}

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
    int i = left, j = right;
    /*printf("Part of sort\n");
    print_int_arr(data + left, right - left + 1);*/

    while(true) {
        while(data[i] < pivot) i++;
        while(data[j] > pivot) j--;
        if(i >= j) return j;
        swap_int(&data[i++], &data[j--]);
    }
}

int it = 0;

/*static void sort_3_int(int data[]) {
    if (data[0] > data[2])
        swap_int(&data[0], &data[2]);
    if (data[0] > data[1])
        swap_int(&data[0], &data[1]);
    if (data[1] > data[2])
        swap_int(&data[1], &data[2]);
}*/

void quick_sort_int(int data[], int left, int right) {
    if (right - left == 1 && data[right] < data[left]) {
        swap_int(&data[left], &data[right]);
        return;
        }
    /*else if (right - left == 2) {
        sort_3_int(data);
    }*/

    else if (left < right && right - left > 1) {
        int p = partition_(data, left, right);
        //print_int_arr(data, 13);  //print array in i if len == 10
        if(it == 10000) {     //to avoid inf loop
            printf("To many iterations");
            _Exit (EXIT_SUCCESS);
            }
        //printf("pivo - %d\n", p);
        it++;
        quick_sort_int(data, left, p);
        quick_sort_int(data, p + 1, right);
    }
}
