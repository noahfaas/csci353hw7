#include <iostream>
#include "divide_and_conquer.h"

using namespace std;

void test_count_ones(int arr[], int n, int expected)
{
    int result = count_ones(arr, n);
    cout << "Testing count_ones" << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result:   " << result << endl;
    cout << "------------------------" << endl;
}

void test_count_target(int arr[], int n, int t, int expected)
{
    int result = count_target(arr, n, t);
    cout << "Testing count_target" << endl;
    cout << "Target: " << t << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result:   " << result << endl;
    cout << "------------------------" << endl;
}

int main()
{
    int a1[] = {0,0,0,0};
    test_count_ones(a1, 4, 0);

    int a2[] = {1,1,1,1};
    test_count_ones(a2, 4, 4);

    int a3[] = {0,0,1,1,1};
    test_count_ones(a3, 5, 3);

    int a4[] = {0};
    test_count_ones(a4, 1, 0);

    int a5[] = {1};
    test_count_ones(a5, 1, 1);

    int b1[] = {1,2,2,2,3,4};
    test_count_target(b1, 6, 2, 3);

    int b2[] = {1,1,1,1};
    test_count_target(b2, 4, 1, 4);

    int b3[] = {1,2,3,4};
    test_count_target(b3, 4, 5, 0);

    int b4[] = {5,5,5,5,5};
    test_count_target(b4, 5, 5, 5);

    int b5[] = {1,2,3,3,3,4,5};
    test_count_target(b5, 7, 3, 3);

    return 0;
}
