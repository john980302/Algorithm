#include <iostream>

long long int arr[101];
int n, t;

int main() {

	std::cin >> t;

	arr[1] = 1; arr[2] = 1; arr[3] = 1;

	for (int i = 1; i <= t; i++) {
		std::cin >> n;
		for (int j = 4; j <= n; j++) {
			arr[j] = arr[j - 2] + arr[j - 3];
		}
		printf("%lld\n", arr[n]);
	}

	return 0;
}