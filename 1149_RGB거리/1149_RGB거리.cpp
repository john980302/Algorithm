#include <iostream>

const int R = 0;
const int G = 1;
const int B = 2;
const int max_size = 1000;

int smaller2(int a, int b) {
	return a <= b ? a : b;
}
int smaller3(int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}

int main() {
	int arr[max_size][3];
	int h_num; // Áý ¼ö
	std::cin >> h_num;

	for (int i = 0; i < h_num; i++) {
		std::cin >> arr[i][R] >> arr[i][G] >> arr[i][B];
	}

	int memo[max_size][3];
	memo[0][R] = arr[0][R]; memo[0][G] = arr[0][G]; memo[0][B] = arr[0][B];

	for (int i = 1; i < h_num; i++) {
		memo[i][R] = smaller2(memo[i - 1][G] + arr[i][R], memo[i - 1][B] + arr[i][R]);
		memo[i][G] = smaller2(memo[i - 1][R] + arr[i][G], memo[i - 1][B] + arr[i][G]);
		memo[i][B] = smaller2(memo[i - 1][R] + arr[i][B], memo[i - 1][G] + arr[i][B]);
	}

	int ans = smaller3(memo[h_num - 1][R], memo[h_num - 1][G], memo[h_num - 1][B]);

	std::cout << ans << "\n";

	return 0;
}