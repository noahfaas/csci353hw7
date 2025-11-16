#ifndef FAKE_COIN_H
#define FAKE_COIN_H

int weigh(int arr[], int start1, int stop1, int start2, int stop2) {
    int sum1 = 0;
    int sum2 = 0;
    int i;

    for (i = start1; i <= stop1; i++) {
        sum1 = sum1 + arr[i];
    }
    for (i = start2; i <= stop2; i++) {
        sum2 = sum2 + arr[i];
    }

    if (sum1 > sum2) {
        return -1;
    }
    else if (sum1 < sum2) {
        return 1;
    }
    else {
        return 0;
    }
}

int find_fake(int arr[], int start, int stop) {
    int n = stop - start + 1;

    if (n == 1) return start;

    if (n == 2) {
        int result = weigh(arr, start, start, stop, stop);
        return (result == -1 ? stop : start);
    }

    if (n == 3) {
        int result = weigh(arr, start, start, start + 1, start + 1);
        if (result == -1) {
            return start + 1;
        }
        else if (result == 1) {
            return start;
        }
        else {
            return start + 2;
        }
    }

    int groupSize = n / 3;

    int start1 = start;
    int stop1 = start1 + groupSize - 1;

    int start2 = stop1 + 1;
    int stop2 = start2 + groupSize - 1;

    int start3 = stop2 + 1;
    int stop3 = stop;

    int result = weigh(arr, start1, stop1, start2, stop2);

    if (result == 1) {
        return find_fake(arr, start1, stop1);
    }
    else if (result == -1) {
        return find_fake(arr, start2, stop2);
    }
    else {
        return find_fake(arr, start3, stop3);
    }
}

#endif
