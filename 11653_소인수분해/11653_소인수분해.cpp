#include <iostream>

int main() {
	// ����
	int n, m;

	// �Է�
	std::cin >> n;
	m = n - 1;

	// ���μ����� ���
	while (n > 3) {
		if (n % m == 0) {
			printf("%d\n", n / m);
			n = m;
		}
		m--;
	}
	// 2�� 3�� �⺻ ���̶� ����ó��
	if (n == 2 || n == 3) {
		printf("%d\n", n);
	}

	return 0;
}