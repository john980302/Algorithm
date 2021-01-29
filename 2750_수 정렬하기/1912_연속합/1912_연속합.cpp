#include <iostream>

int max(int v1, int v2) {
	return v1 > v2 ? v1 : v2;
}

int main() {

	int n;
	std::cin >> n;
	int res = -1001;
	int arr[100001];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			arr[i] = max(arr[i], arr[i] + arr[i - 1]);
		}
		res = max(res, arr[i]);
	
	}
	printf("%d\n", res);
	return 0;
}