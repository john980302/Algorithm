#include <iostream>

int main() {
	int a, b, minab = 0;
	std::cin >> a >> b;

	if (a < b) {
		minab = a;
		a = b;
		b = minab;
	}
	for (int i = 1; i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			minab = i;
		}
	}
	printf("%d\n", minab);
	printf("%d\n", a * b / minab);

	return 0;
}