#include <iostream>
int factorial(int a) {
	int res = 1;
	for (int i = a; i > 0; i--) {
		res *= i;
	}
	return res;
}

int main() {
	int n, k, res = 0;
	std::cin >> n >> k;
	if (0 <= k && n >= k) {
		res = factorial(n) / (factorial(k) * factorial(n - k));
	}
	printf("%d\n", res);

	return 0;
}