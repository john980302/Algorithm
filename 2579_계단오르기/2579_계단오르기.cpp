#include <iostream>

int bigger2(int a, int b) {
	return (a > b) ? a : b;
}
int n;
int arr[300], dp[300];

int main() {

	// 입력 받는 부분
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	// 계산 부분
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = bigger2(dp[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = bigger2((dp[i - 2] + arr[i]), (dp[i - 3] + arr[i - 1] + arr[i]));
	}

	// 출력 부분
	std::cout << dp[n-1] << "\n";

	return 0;
}