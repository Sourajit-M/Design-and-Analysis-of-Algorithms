#include <stdio.h>

void sortJobsByProfit(int J[], int D[], int P[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (P[j] < P[j+1]) {
                int temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;

                temp = D[j];
                D[j] = D[j+1];
                D[j+1] = temp;

                temp = J[j];
                J[j] = J[j+1];
                J[j+1] = temp;
            }
        }
    }
}

int JobSeqWD(int J[], int D[], int P[], int n) {
    sortJobsByProfit(J, D, P, n);
    
    int profit = 0;

    int max = D[0];
    for (int i = 1; i < n; i++) {
        if (D[i] > max)
            max = D[i];
    }

    int timeslot[max+1];
    for (int i = 0; i <= max; i++) {
        timeslot[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int k = D[i];
        while (k >= 1) {
            if (timeslot[k] == 0) {
                timeslot[k] = J[i];
                profit += P[i];
                break;
            }
            k--;   
        }
    }

    printf("Jobs scheduled: ");
    for (int i = 1; i <= max; i++) {
        if (timeslot[i] != 0) {
            printf("%d ", timeslot[i]);
        }
    }
    printf("\n");

    return profit;
}

int main() {
    int n = 5;

    int J[] = {1, 2, 3, 4, 5};
    int D[] = {3, 1, 4, 2, 2};
    int P[] = {10, 30, 20, 50, 40};


    int res = JobSeqWD(J, D, P, n);

    printf("Total profit: %d\n", res);

    return 0;
}
