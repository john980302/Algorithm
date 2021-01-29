#include <iostream>
#include <algorithm>

int main() {

	int t, n, res;
	char arr[100000][5] = { 'a', };
	int dp[100000];
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> arr[j];
			dp[j] = 0;
		}
		
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				res = 0;
				for (int l = 0; l < 4; l++) {
					if (arr[j][l] != arr[k][l]) {
						res++;
					}
				}
				dp[j] = res;
			}
		}
		printf("dp[i]: ");
		for (int j = 0; j < n; j++) {
			printf("%d ", dp[j]);
		}
		printf("\ndp[i]: ");
		std::sort(dp, dp + n );
		res = dp[0] + dp[1] + dp[2];

		for (int j = 0; j < n; j++) {
			printf("%d ", dp[j]);
		}


		printf("%d\n", res);
	}
	
	


	return 0;
}