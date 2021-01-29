#include <iostream>

int main() {
	// 0 <= m <= n <= 2,000,000,000, n != 0
	// m에서 5의 13승까지, 2의 30승까지 
	int n, m, fact2 = 0, fact5 = 0, res = 0, pow_ = 1;

	std::cin >> n >> m;

	// 2의 개수
	pow_ = 1;
	for (int i = 1; i <= 30; i++) {
		pow_ *= 2;
		fact2 += (n / pow_);
		fact2 -= (m / pow_);
		fact2 -= ((n - m) / pow_);
	}
		

	// 5의 개수
	pow_ = 1;
	for (int i = 1; i <= 13; i++) {
		pow_ *= 5;
		fact5 += (n / pow_);
		fact5 -= (m / pow_);
		fact5 -= ((n - m) / pow_);
	}

	res = fact2 > fact5 ? fact5 : fact2;

	printf("%d\n", res);


	return 0;
}