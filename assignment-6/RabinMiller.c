#include <stdio.h>
#include <stdlib.h>

long long modular_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Rabin-Miller primality test
int is_prime(int n, int k) {
    if (n <= 1 || n == 4) return 0; 
    if (n <= 3) return 1;          
    int d = n - 1;
    while (d % 2 == 0) d /= 2; 

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4);
        long long x = modular_pow(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        int is_composite = 1;
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;
            if (x == 1) return 0;       
            if (x == n - 1) {         
                is_composite = 0;
                break;
            }
        }
        if (is_composite) return 0;  
    }
    return 1; 
}

int main() {
    int n, k = 5;
    printf("Enter the number to test: ");
    scanf("%d", &n);

    if (is_prime(n, k))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}
