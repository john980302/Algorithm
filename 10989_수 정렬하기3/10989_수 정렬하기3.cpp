#include <iostream>

int main() {

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	int arr[10000] = { 0, };
	int idx;
	for (int i = 0; i < n; i++) {
		std::cin >> idx;
		arr[idx-1]++;
	}

	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			std::cout << i+1 << "\n";
		}
	}


	return 0;
}