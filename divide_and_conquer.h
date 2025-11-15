#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

int count_ones(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int firstOne = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == 1)
        {
            firstOne = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return n - firstOne;
}

int count_target(int arr[], int n, int t)
{
    int left, right, mid;

    int first = n;
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] >= t)
        {
            first = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (first == n || arr[first] != t)
    {
        return 0;
    }

    int firstGreater = n;
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] > t)
        {
            firstGreater = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return firstGreater - first;
}

#endif
