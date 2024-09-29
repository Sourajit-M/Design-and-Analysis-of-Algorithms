#include <stdio.h>

void mergeSort(int a[], int n);
void merge(int arr[], int si, int mid, int ei);
void printArray(int arr[], int n);

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, len);

    mergeSort(arr, len-1);

    printf("Sorted array:\n");
    printArray(arr, len);
    return 0;
}

void mergeSort(int arr[], int n){
    int p, i, s, e, mid;
    for(p=2; p<=n; p*=2){
        for(i=0; i+p-1<=n; i+=p){
            s = i;
            e = i+p-1;
            mid = (e+s)/2;

            merge(arr, s, mid, e);
        }
    }

    if(p/2 < n){
        merge(arr, 0, p/2-1, n-1);
    }
}

void merge(int arr[], int si, int mid, int ei){
    int temp[ei-si+1];
    int i = si;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=ei){
        temp[k++] = arr[j++];
    }

    for (k = 0, i = si; k < ei - si + 1; k++, i++) {
    arr[i] = temp[k];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}