#include<iostream>
using namespace std;

int max(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int maxProductSubarray(int arr[], int left, int right, int *start, int *end) {

    if (left == right) {
        *start = left;
        *end = right;
        return arr[left];
    }

    int mid = (left + right) / 2;

    int maxLeft, maxRight;
    int startLeft, endLeft, startRight, endRight;
    maxLeft = maxProductSubarray(arr, left, mid, &startLeft, &endLeft);
    maxRight = maxProductSubarray(arr, mid + 1, right, &startRight, &endRight);

    int maxLeftCrossing = 1;
    int maxRightCrossing = 1;
    int minLeftCrossing = 1;
    int minRightCrossing = 1;
    int product = 1;
    int crossingStart, crossingEnd;
    for (int i = mid; i >= left; i--) {
        product *= arr[i];
        if (product > maxLeftCrossing) {
            maxLeftCrossing = product;
            crossingStart = i;
        }
        if (product < minLeftCrossing) {
            minLeftCrossing = product;
        }
    }
    product = 1;
    for (int i = mid + 1; i <= right; i++) {
        product *= arr[i];
        if (product > maxRightCrossing) {
            maxRightCrossing = product;
            crossingEnd = i;
        }
        if (product < minRightCrossing) {
            minRightCrossing = product;
        }
    }
    int maxCrossing = maxLeftCrossing * maxRightCrossing;
    *start = crossingStart;
    *end = crossingEnd;

    if (maxLeft >= maxRight && maxLeft >= maxCrossing) {
        *start = startLeft;
        *end = endLeft;
        return maxLeft;
    } else if (maxRight >= maxLeft && maxRight >= maxCrossing) {
        *start = startRight;
        *end = endRight;
        return maxRight;
    } else {
        return maxCrossing;
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start, end;
    int maxProduct = maxProductSubarray(arr, 0, n - 1, &start, &end);
    cout << "Maximum product subarray: " << maxProduct <<endl;
    cout << "Start index : " << start << endl;
    cout << "End index: " << end << endl;

    return 0;
}
