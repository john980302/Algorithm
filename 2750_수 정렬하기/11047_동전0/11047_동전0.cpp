#include <iostream>

int main() {
	// ����
	int n, k, res = 0;
	int a[10] = { 0, };

	// �Է�
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// ���
	for (int i = n - 1; i >= 0; i--) {
		if (k / a[i] > 0) {
			res += k / a[i];
			k -= (k / a[i]) * a[i];
		}
	}

	printf("%d\n", res);

	return 0;
}