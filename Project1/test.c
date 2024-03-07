#include <stdio.h>

int main() {
	int sum = 0;
	int n = 0;
	int i;
	scanf_s("%n", &n);
	for (i = 0; i < n; i++) {
		sum = sum + i;
	}
	pritnf("%n", sum);
}