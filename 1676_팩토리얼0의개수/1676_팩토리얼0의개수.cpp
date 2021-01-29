#include <iostream>

long long int divide(long long int n, long long int d) {
	long long int res = 0;
	while (1) {
		if (n % d != 0) {
			break;
		}
		else {
			n /= d;
			res++;
		}
	}
	return res;
}

int main() {
	long long int n, i, five = 0, two = 0;
	std::cin >> n;

	for (i = 1; i <= n; i++) {
		five += divide(i, 5);
		two += divide(i, 2);
	}

	if (five > two) {
		printf("%d\n", two);
	}
	else {
		printf("%d\n", five);
	}

	return 0;
}

