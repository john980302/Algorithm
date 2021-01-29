#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int n, cnt = 0, dp_max = 0; cin >> n;
	int num[501], dp[501];
	fill_n(num, 501, 0);
	fill_n(dp, 501, 1);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		cin >> num[tmp];
	}

	for (int i = 1; i <= 500; i++) {
		int tmp = 1;
		for (int j = 1; j < i; j++) {
			if (num[i] != 0) {
				if (num[i] > num[j] && num[j] != 0)
					tmp = max(tmp, dp[j] + 1);
			}
		}
		dp[i] = tmp;
		if (dp[i] > dp_max)
			dp_max = dp[i];
	}
	cout << n - dp_max;
}