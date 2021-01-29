#include <iostream>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	// ������ �Է�
	int n, k;
	int w[101] = { 0, }, v[101] = { 0, };
	// �����Ҵ�
	int** dp = new int* [101];
	for (int i = 0; i < 101; i++) {
		dp[i] = new int[100001];
	}
	// �ʱ�ȭ
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 100001; j++) {
			dp[i][j] = 0;
		}
	}
	
	// �Է�
	std::cin >> n >> k;
	for (int i = 1; i < n+1; i++) {
		std::cin >> w[i] >> v[i];
	}

	// ���
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (w[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
			}
		}
		
	}
	/*
	// ���
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/
	
	// ���� ���
	std::cout << dp[n][k];

	// �����Ҵ� ����
	for (int i = 0; i < 101; i++) {
		delete[] dp[i];
	}
	delete[] dp;


	return 0;
}