#include <iostream>

int main() {
	// 변수
	int n, k, res = 0;
	int a[10] = { 0, };

	// 입력
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// 계산
	for (int i = n - 1; i >= 0; i--) {
		if (k / a[i] > 0) {
			res += k / a[i];
			k -= (k / a[i]) * a[i];
		}
	}

	printf("%d\n", res);

	return 0;
}