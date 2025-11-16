#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

int count_ones(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int first_one = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == 1) {
            firstOne = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return n - first_one;
}

int count_target(int arr[], int n, int t) {
    int left, right, mid;

    int first = n;
    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] >= t) {
            first = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (first == n || arr[first] != t) {
        return 0;
    }

    int first_greater = n;
    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] > t) {
            first_greater = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return first_greater - first;
}

#endif
