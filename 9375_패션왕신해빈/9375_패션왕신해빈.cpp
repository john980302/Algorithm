#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int t, n, idxarr[30] = { 0, }, find_idx, res = 1;
	std::string wear, wearname;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		// n �Է�
		std::cin >> n;

		// idxarr �ʱ�ȭ(n ũ��)
		for (int j = 0; j < n; j++) {
			idxarr[j] = 0;
		}
		res = 1;

		// �ǻ��� ������ ������ vector
		std::vector<std::string> warr;
		for (int j = 0; j < n; j++) {
			std::cin >> wear >> wearname;
			find_idx = std::find(warr.begin(), warr.end(), wearname) - warr.begin();
			if (find_idx  == warr.size()) {
				warr.push_back(wearname);
				idxarr[find_idx] = 1;
			}
			else {
				idxarr[find_idx]++;
			}
		}
		for (int j = 0; j < n; j++) {
			res *= (idxarr[j] + 1);
		}
		res--;
		printf("%d\n", res);
	}


	return 0;
}