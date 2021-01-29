#include <iostream>

int main() {
	// 변수
	int n, m;

	// 입력
	std::cin >> n;
	m = n - 1;

	// 소인수분해 계산
	while (n > 3) {
		if (n % m == 0) {
			printf("%d\n", n / m);
			n = m;
		}
		m--;
	}
	// 2와 3은 기본 값이라서 예외처리
	if (n == 2 || n == 3) {
		printf("%d\n", n);
	}

	return 0;
}