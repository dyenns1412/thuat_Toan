#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
//primes lưu các giá trị nguyên tố từ 2 đến n
//len độ dài mảng prime
//res mảng lưu các giá trị cần tìm
// pos là đồ dài của res
void find_primes(int n, int m, int primes[], int len, int res[], int pos) {


    if (n == 0 && m == 0) {// nếu m =0 và n = 0 tức là phân tích được
        for (int i = pos - 1; i >= 0; i--) {
                if(i != 0)
            printf("%d,", res[i]);
        else printf("%d", res[i]);
        }
        printf("\n");
        return;
    }
    if (n <= 0 || m <= 0) {// không phân tích đượcc
        return;
    }

    for (int i = 0; i < len; i++) {
        if (n >= primes[i]) {
            res[pos] = primes[i];
           find_primes(n - primes[i], m - 1, primes, i, res, pos + 1);//thực hiện đệ quy vét tất cả các trường hợp xẩy ra
        }
    }
}

int main() {
    int n, m;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    printf("Nhap so nguyen to m: ");
    scanf("%d", &m);
    int primes[100] = {0};
    int len = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            primes[len++] = i;
        }
    }
    int res[100] = {0};
    find_primes(n, m, primes, len, res, 0);
    return 0;
}
