#include <iostream>

int main() {
	int t = 0, a = 0, b = 0, big = 0, small = 0, mv = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;
		if (b > a) {
			big = b;
			small = a;
		}
		else {
			big = a;
			small = b;
		}
		for (int k = big; k > 0; k--) {
			if (b % k == 0 && a % k == 0) {
				mv = k;
				break;
			}
		}
		printf("%d\n", a * b / mv);
	}


	return 0;
}