#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primenum(int n) {  // 소수를 판별하는 함수 정의
    if (n <= 1) {  // 상수 시간 (1번의 비교)
        return 0;  // 소수가 아니므로 0 반환
    }
    for (int i = 2; i * i <= n; i++) {  // 최대 n의 제곱근까지 반복, n의 제곱근 이하로 나누어 떨어지지 않으면 소수이다.
        if (n % i == 0) {  // 나머지 연산: 상수 시간 (1번의 나눗셈, 1번의 비교)
            return 0;  // 소수가 아니므로 0 반환
        }
    }
    return 1;  // 소수임을 나타내는 1 반환
}

int main() {
    clock_t start, stop;
    double duration; //이상 시간계산 변수 설정
    start = clock(); // 시간기록 시작

    int sum = 0;

    for (int i = 0; i <= 100; i++) {  // n번 반복 (100번으로 설정)
        if (primenum(i) == 1) {  // primenum 함수 호출: O(√n)
            sum += i;
        }
    }
    stop = clock();  // 시간기록 완료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 시간 계산

    printf("0부터 n까지의 소수의 합은 %d입니다.\n", sum);
    printf("처리시간은 %f초입니다.\n", duration);
    return 0;
}
