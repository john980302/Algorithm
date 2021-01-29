#include <iostream>

int bigger2(int a, int b) {
	return (a > b) ? a : b;
}

int n; // 1 <= n <= 500
int arr[500][500];
int memo[500][500];

int main() {
	
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	memo[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j - 1 < 0) {
				memo[i][j] = memo[i - 1][j] + arr[i][j];
			}
			else if (j + 1 > i) {
				memo[i][j] = memo[i - 1][j - 1] + arr[i][j];
			}
			else {
				memo[i][j] = bigger2(memo[i - 1][j - 1] + arr[i][j], memo[i - 1][j] + arr[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = bigger2(ans, memo[n - 1][i]);
	}

	printf("%d\n", ans);





	return 0;
}