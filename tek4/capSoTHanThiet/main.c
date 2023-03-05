#include <stdio.h>

int main() {
    int n, i, j, sum, temp;
    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        sum = 0;
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        temp = sum;
        sum = 0;
        for (j = 1; j < temp; j++) {
            if (temp % j == 0) {
                sum += j;
            }
        }
        if (i == sum && i < temp) {
            printf("%d %d\n", i, temp);
        }
    }
    return 0;
}
