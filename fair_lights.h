#ifndef FAIR_LIGHTS_H
#define FAIR_LIGHTS_H

#include <iostream>

void toggle(int arr[], int index) {
    if (arr[index] == 0) arr[index] = 1;
    else arr[index] = 0;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i];
    std::cout << std::endl;
}

void try_all_helper(int arr[], int n, int index, int stop) {
    if (index > stop) {
        print_array(arr, n);
        return;
    }

    try_all_helper(arr, n, index + 1, stop);

    toggle(arr, index);
    try_all_helper(arr, n, index + 1, stop);
}

void try_all(int arr[], int n, int stop) {
    try_all_helper(arr, n, 0, stop);
}

#endif
