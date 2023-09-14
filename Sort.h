#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>

void bubble_sort_int(int data[], int size_);
void selection_sort_int(int data[], int size_);
void print_int_arr(int* a, int nums);
void quick_sort_int(int data[], int left, int right);

#endif // SORT_H_INCLUDED
