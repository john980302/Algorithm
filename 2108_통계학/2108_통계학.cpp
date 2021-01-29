#include <iostream>
#include <cmath>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	int l, minv = 4001, maxv = -4001;
	int arr2[8001] = { 0, };
	int s = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> l;
		s += l;
		if (l > maxv) {
			maxv = l;
		}
		if (l < minv) {
			minv = l;
		}
		l += 4000;
		arr2[l]++;

	}
	int ss = round((double)s / (double)n);
	// 산술평균 출력
	std::cout << ss << "\n";

	// // 중앙값 출력, 최빈값 출력
	int most1 = 0, mv = 0, cnt = 0;
	for (int i = 0; i < 8001; i++) {
		cnt += arr2[i];
		if (cnt >= (n + 1) / 2) {
			std::cout << i - 4000 << "\n";
			cnt -= n;
		}
		if (arr2[i] > mv) {
			mv = arr2[i];
			most1 = i - 4000;
		}
	}
	for (int i = most1 + 4001; i < 8001; i++) {
		if (arr2[i] == arr2[most1 + 4000]) {
			most1 = i - 4000;
			break;
		}
	}
	std::cout << most1 << "\n";


	// 범위 출력
	std::cout << maxv - minv << "\n";

	return 0;
}