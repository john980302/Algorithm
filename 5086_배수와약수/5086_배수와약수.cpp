#include <iostream>

int main() {
	int a, b;
	while (1) {
		std::cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (b % a == 0) {
			printf("factor\n");
		}
		else if (a % b == 0) {
			printf("multiple\n");
		}
		else {
			printf("neither\n");
		}
	}

	return 0;
}