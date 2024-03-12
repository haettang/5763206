#include <stdio.h>

int primenum(int n) {
    if(n <= 1) {
        return 0;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int sum = 0;

    for(int i = 0; i <= 100; i++) {
        if(primenum(i) == 1) {
            sum += i;
        }
    }

    printf(" 0부터 100까지의 소수의 합은 %d입니다.\n", sum);
    return 0;
}