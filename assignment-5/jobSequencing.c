#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    char id[3];
    int dead;
    int profit; 
} Job;

int compare(const *a, const *b) {
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}

int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int maxProfit = 0;
    printf("Maximum profit sequence of jobs:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%s ", arr[result[i]].id);
            maxProfit += arr[result[i]].profit;
        }
    }
    printf("\nTotal maximum profit: %d\n", maxProfit);
}

int main() {
        Job arr[] = { { "J1", 3, 35 },
                    { "J2", 4, 30 },
                    { "J3", 4, 25 },
                    { "J4", 2, 20 },
                    { "J5", 3, 15 },
                    { "J6", 1, 12 },
                    { "J7", 2, 5 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    printJobScheduling(arr, n);
    return 0;
}
