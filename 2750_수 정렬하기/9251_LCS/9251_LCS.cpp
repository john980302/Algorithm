#include <iostream>
#include <cstring>

int max(int v1, int v2) {
	return v1 > v2 ? v1 : v2;
}

int main() {
	// 입력 부분
	char arr1[1000], arr2[1000];
	int** dp = new int* [1001];
	dp[0] = new int[1001 * 1001];
	for (int i = 0; i < 1001; i++) {
		dp[i] = dp[0] + 1001 * i;
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = 0;
		}
	}
	std::cin >> arr1;
	std::cin >> arr2;

	// arr1에서의 처음 글자부터 마지막 글자까지 arr2에 존재하는 지를 확인한다.
	for (int i = 0; i < strlen(arr1); i++) {
		for (int j = 0; j < strlen(arr2); j++) {
			if (arr1[i] == arr2[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}	
	}
	printf("%d", dp[strlen(arr1)][strlen(arr2)]);

	delete[] dp[0];
	delete[] dp;

	return 0;
}