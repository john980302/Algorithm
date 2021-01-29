#include <iostream>
double two(int n, int k) {
	double r = 1;
	for (double i = n; i > n - k; i--) {
		r *= i;
		r /= i - (n - k);

	}
	return r;
}

int main() {
	int t, n, m, k;
	double res = 1;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		res = 1;
		std::cin >> n >> m;
		if (m - n > 0) {
			k = m - n;
			res = two(m, k);
		}
		printf("%.f\n", res);
	}


	return 0;
}