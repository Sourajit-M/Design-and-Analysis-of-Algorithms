#include <stdio.h>

void swap(float arr[][2], int i, int j) {
    float temp0 = arr[i][0];
    float temp1 = arr[i][1];
    arr[i][0] = arr[j][0];
    arr[i][1] = arr[j][1];
    arr[j][0] = temp0;
    arr[j][1] = temp1;
}

int partition(float arr[][2], int low, int high) {
    int i = low + 1;
    int j = high;
    int pivot = low;

    while (i <= j) {
        while (i <= high && arr[i][1] <= arr[pivot][1]) {
            i++;
        }

        while (j >= low && arr[j][1] > arr[pivot][1]) {
            j--;
        }

        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, pivot, j);
    return j;
}

void quickSort(float arr[][2], int low, int high) {
    if (low >= high) {
        return;
    }

    int pIdx = partition(arr, low, high);
    quickSort(arr, low, pIdx - 1);
    quickSort(arr, pIdx + 1, high);
}

void fractionalKnapsack(int b[], int wt[], int W, int n) {
    float val[n][2];

    for (int i = 0; i < n; i++) {
        val[i][0] = i;
        val[i][1] = b[i] / (float)wt[i];
    }

    quickSort(val, 0, n - 1);

    float finalVal = 0.0;
    int w = W;

    for (int i = n - 1; i >= 0; i--) {
        int idx = (int)val[i][0];
        if (wt[idx] <= w) {
            w -= wt[idx];
            finalVal += b[idx];
        } else {
            finalVal += (b[idx] * (float)w / wt[idx]);
            break;
        }
    }

    printf("Maximum value of knapsack = %.2f\n", finalVal);
}

int main() {
    int b[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;

    fractionalKnapsack(b, wt, W, 3);

    return 0;
}