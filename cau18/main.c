#include <stdio.h>
#include <math.h>

#define W 8

int solve(int a,  int t, int* result) {
    int i, n[t];
    for (i = 0; i < t; i++) {
        n[i] = pow(2, i * W);
    }
    for (i = t-1; i >= 0; i--) {
        result[i] = a / n[i];
        a = a % n[i];
    }
    return 0;
}

void solve_plus(int* a, int* b,int t) {
    int i, epsilon = 0, c[t];
    for (i = 0; i < t; i++) {
        int tong = a[i] + b[i] + epsilon;
        if (tong < 0 || tong > pow(2, W)) {
            epsilon = 1;
        } else {
            epsilon = 0;
        }
        tong = tong % (int)pow(2, W);
        c[i] = tong;
    }
    printf("%d ", epsilon);
    for (i = t-1; i >= 0; i--) {
        printf("%d", c[i]);
    }
    printf("\n");
}

int main() {
    int num_1, num_2, p = 2147483647, m, t, i;
    int a[32], b[32];
    printf("Enter the first number: ");
    scanf("%d", &num_1);
    printf("Enter the second number: ");
    scanf("%d", &num_2);
    m = ceil(log2(p));
    t = ceil((double)m / W);
    solve(num_1, t, a);
    solve(num_2, t, b);
    for (i = 0; i < t/2; i++) {
        int temp = a[i];
        a[i] = a[t-1-i];
        a[t-1-i] = temp;
        temp = b[i];
        b[i] = b[t-1-i];
        b[t-1-i] = temp;
    }
    printf("Addition algorithm: ");
    solve_plus(a, b, t);
    printf("%d + %d = %d\n", num_1, num_2, num_1 + num_2);
    return 0;
}
