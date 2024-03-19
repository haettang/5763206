#include <stdio.h>
#include <time.h>

long long power_iter(long long x, int n) {
    int i;
    long long result = 1;
    for (i = 0; i < n; i++) {
        result = result * x;
    }
    return(result);
}
long long power_rec(long long x, int n) {
    if (n == 0) return 1;
    else if ((n % 2) == 0) {
        long long y = power_rec(x, n / 2);
        return y * y;
    }
    else return x * power_rec(x * x, (n - 1) / 2);
}

int main() {
    clock_t start_rec, end_rec, start_iter, end_iter;
    
    start_rec = clock();
    long long result_rec = power_rec(13, 21);
    end_rec = clock();
    printf("\n걸린 시간 : %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);
    printf("재귀적 결과: %lld\n", result_rec);

    start_iter = clock();
    long long result_iter = 0;
    result_iter = power_iter(13, 21);
    end_iter = clock();
    printf("\n걸린 시간 : %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
    printf("반복적 결과 : %lld\n", result_iter);
}
