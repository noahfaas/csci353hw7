#include <iostream>
#include "divide_and_conquer.h"
#include "fake_coin.h"
#include "fair_lights.h"

using namespace std;

// Tests for count_ones
void test_count_ones(int arr[], int n, int expected)
{
    int result = count_ones(arr, n);
    cout << "Testing count_ones" << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result:   " << result << endl;
    cout << "------------------------" << endl;
}

// Tests for count_target
void test_count_target(int arr[], int n, int t, int expected)
{
    int result = count_target(arr, n, t);
    cout << "Testing count_target" << endl;
    cout << "Target: " << t << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result:   " << result << endl;
    cout << "------------------------" << endl;
}

// Tests for find_fake
void test_find_fake(int arr[], int n, int expectedIndex)
{
    cout << "Testing find_fake" << endl;
    cout << "Array (weights): ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = find_fake(arr, 0, n - 1);

    cout << "Expected fake coin index: " << expectedIndex << endl;
    cout << "Result fake coin index:   " << result << endl;
    cout << "------------------------" << endl;
}

// Tests for try_all
void test_try_all(int arr[], int n, int stop)
{
    cout << "Testing try_all" << endl;
    cout << "Start array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    cout << "Toggling indices 0 through " << stop << endl;
    cout << "Generated configurations:" << endl;
    try_all(arr, n, stop);
    cout << "------------------------" << endl;
}

int main()
{
    // count_ones tests
    int a1[] = {0, 0, 0, 0};
    test_count_ones(a1, 4, 0);

    int a2[] = {1, 1, 1, 1};
    test_count_ones(a2, 4, 4);

    int a3[] = {0, 0, 1, 1, 1};
    test_count_ones(a3, 5, 3);

    int a4[] = {0};
    test_count_ones(a4, 1, 0);

    int a5[] = {1};
    test_count_ones(a5, 1, 1);

    // count_target tests
    int b1[] = {1, 2, 2, 2, 3, 4};
    test_count_target(b1, 6, 2, 3);

    int b2[] = {1, 1, 1, 1};
    test_count_target(b2, 4, 1, 4);

    int b3[] = {1, 2, 3, 4};
    test_count_target(b3, 4, 5, 0);

    int b4[] = {5, 5, 5, 5, 5};
    test_count_target(b4, 5, 5, 5);

    int b5[] = {1, 2, 3, 3, 3, 4, 5};
    test_count_target(b5, 7, 3, 3);

    // find_fake tests
    int c1[] = {10, 10, 9, 10, 10, 10, 10, 10, 10};
    test_find_fake(c1, 9, 2);

    int c2[] = {5, 5, 5, 4, 5, 5};
    test_find_fake(c2, 6, 3);

    int c3[] = {7, 6, 7};
    test_find_fake(c3, 3, 1);

    int c4[] = {3, 2};
    test_find_fake(c4, 2, 1);

    int c5[] = {1};
    test_find_fake(c5, 1, 0);

    // try_all test
    int d1[] = {0, 1, 0, 1, 1};
    test_try_all(d1, 5, 2);

    return 0;
}
