#include <stdio.h>
#include <stdbool.h>

int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void prime_factors(int n, int factors[]) {
    int i = 2, count = 0;
    while (n > 1) {
        if (n % i == 0) {
            factors[count++] = i;
            n /= i;
        } else {
            i++;
        }
    }
}

bool is_smith(int n) {
    int sum_digits = digit_sum(n);

    if (sum_digits == 1) {
        return false;
    }

    int factors[32] = {0};
    prime_factors(n, factors);

    int sum_factors = 0;
    for (int i = 0; factors[i] != 0; i++) {
        sum_factors += digit_sum(factors[i]);
    }

    return sum_digits == sum_factors;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int dem = 0;
        for (int i = l; i <= r; i++) {
            if (is_smith(i)) {
               dem++;
            }
        }
         printf("%d\n", dem);
    }

    return 0;
}
