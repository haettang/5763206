#include <stdio.h>
#include <time.h>

long long factorial_rec(int n) {
    if (n <= 1) return (1);
    else return (n * factorial_rec(n - 1));
}

long long factorial_iter(int n) {
    int k;
    long long v = 1;
    for (k = n; k > 0; k--) {
        v = v * k;
    }
    return(v);
}

int main() {
    clock_t start_rec, end_rec, start_iter, end_iter;
    
    start_rec = clock();
    long long result_rec = factorial_rec(20);
    end_rec = clock();
    printf("\n걸린 시간 : %f\n", (float)(end_rec - start_rec) / CLOCKS_PER_SEC);
    printf("재귀적 결과: %lld\n", result_rec);

    start_iter = clock();
    long long result_iter = 0;
    result_iter = factorial_iter(20);
    end_iter = clock();
    printf("\n걸린 시간 : %f\n", (float)(end_iter - start_iter) / CLOCKS_PER_SEC);
    printf("반복적 결과 : %lld\n", result_iter);
}