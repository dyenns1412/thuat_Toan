#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int foo(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(n, i) == 1) {
            ret++;
        }
    }
    return ret;
}

int specialSum(int N) {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            ret += foo(i);
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        printf("%d\n", specialSum(N));
    }

    return 0;
}

