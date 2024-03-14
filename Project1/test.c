#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primenum(int n) {  // �Ҽ��� �Ǻ��ϴ� �Լ� ����
    if (n <= 1) {  // ��� �ð� (1���� ��)
        return 0;  // �Ҽ��� �ƴϹǷ� 0 ��ȯ
    }
    for (int i = 2; i * i <= n; i++) {  // �ִ� n�� �����ٱ��� �ݺ�, n�� ������ ���Ϸ� ������ �������� ������ �Ҽ��̴�.
        if (n % i == 0) {  // ������ ����: ��� �ð� (1���� ������, 1���� ��)
            return 0;  // �Ҽ��� �ƴϹǷ� 0 ��ȯ
        }
    }
    return 1;  // �Ҽ����� ��Ÿ���� 1 ��ȯ
}

int main() {
    clock_t start, stop;
    double duration; //�̻� �ð���� ���� ����
    start = clock(); // �ð���� ����

    int sum = 0;

    for (int i = 0; i <= 100; i++) {  // n�� �ݺ� (100������ ����)
        if (primenum(i) == 1) {  // primenum �Լ� ȣ��: O(��n)
            sum += i;
        }
    }
    stop = clock();  // �ð���� �Ϸ�
    duration = (double)(stop - start) / CLOCKS_PER_SEC;  // �ð� ���

    printf("0���� n������ �Ҽ��� ���� %d�Դϴ�.\n", sum);
    printf("ó���ð��� %f���Դϴ�.\n", duration);
    return 0;
}
