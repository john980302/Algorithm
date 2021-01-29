#include <iostream>

int gcd(int a, int b) {
	int r;
	if (a < b) {
		r = a;
		a = b;
		b = r;
	}
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n, arr[100] = { 0, };
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		int gcd_v = gcd(arr[0], arr[i]);
		printf("%d/%d\n", arr[0] / gcd_v, arr[i] / gcd_v);
	}

	return 0;
}