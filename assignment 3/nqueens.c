#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 8

typedef struct {
    int *C;
    int no_queen;
} BOARD;

void initialisation(BOARD *, int);
void display_board(BOARD, int, int *);
int is_safe(BOARD, int, int);
void n_queen(BOARD *, int, int, int *);

void initialisation(BOARD *B, int n) {
    B->no_queen = n;
    B->C = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
        B->C[i] = -1;
}

void display_board(BOARD B, int n, int *a_sol_no) {
    printf("\n\n Solution %d ", ++(*a_sol_no));
    for (int i = 1; i <= n; i++) {
        printf("\n");
        for (int j = 1; j <= n; j++) {
            if (B.C[i] == j)
                printf(" Q");
            else
                printf(" X");
        }
    }
}

int is_safe(BOARD B, int x, int y) {
    for (int i = 1; i < x; i++) {
        if (B.C[i] == y || abs(x - i) == abs(y - B.C[i]))
            return 0;
    }
    return 1;
}

void n_queen(BOARD *B, int k, int n, int *a_sol_no) {
    for (int j = 1; j <= n; j++) {
        if (is_safe(*B, k, j)) {
            B->C[k] = j;
            if (k == n)
                display_board(*B, n, a_sol_no);
            else
                n_queen(B, k + 1, n, a_sol_no);
        }
    }
}

int main() {
    BOARD *p;
    int sol_no = 0;
    p = (BOARD *)malloc(sizeof(BOARD));
    initialisation(p, 8);
    n_queen(p, 1, 8, &sol_no);
    free(p->C);
    free(p);
    return 0;
}
