#include <iostream>

int main()
{
	// 높이와 너비에 대한 값 얻기
	int m, n;
	std::cin >> n >> m;

	// 정답에 대한 값 저장
	char ans[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				ans[i][j] = 'B';
			}
			else {
				ans[i][j] = 'W';
			}
		}
	}

	// 모양에 대한 정보 얻기
	char** arr;
	arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
		std::cin >> arr[i];
	}
	int cnt = 64;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int tmp = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (arr[i + k][j + l] != ans[k][l]) {
						tmp++;
					}
				}
			}
			if (64 - tmp < tmp) {
				tmp = 64 - tmp;
			}
			if (cnt > tmp) {
				cnt = tmp;
			}
		}
	}

	std::cout << cnt << std::endl;


	return 0;
}