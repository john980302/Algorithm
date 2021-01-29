#include <iostream>
#include <vector>

int main() {
	// ����
	long long n, res = 0, tmp;
	std::vector<long long> km;
	std::vector<long long> oil;

	// �Է�
	std::cin >> n;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> tmp;
		km.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		oil.push_back(tmp);
	}

	// ���
	tmp = oil[0];
	res += tmp * km[0];
	for (int i = 1; i < n - 1; i++) {
		if (tmp > oil[i]) {
			tmp = oil[i];
		}
		res += tmp * km[i];
	}

	printf("%lld\n", res);


	return 0;
}