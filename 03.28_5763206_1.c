#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

//polynomial a = { 3, {4, 3, 2, 1} };
//polynomial b = { 2, {3, 2, 8} };
polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} };
polynomial b = { 3, {5, 2, 1, 10} };

void print_polynomial(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}

polynomial multiply_polynomial(polynomial a, polynomial b) {
	polynomial c;
	c.degree = a.degree + b.degree;

	for (int i = 0; i <= c.degree; i++) c.coef[i] = 0;
	for (int i = 0; i <= a.degree; i++)
		for (int j = 0; j <= b.degree; j++)
			c.coef[i + j] += a.coef[i] * b.coef[j];

	return c;
}

int main() {
	printf("A: ");
	print_polynomial(a);
	printf("B: ");
	print_polynomial(b);

	printf("---------------------------------\n");
	polynomial X = multiply_polynomial(a, b);
	printf("A * B: ");
	print_polynomial(X);

	return 0;
}
