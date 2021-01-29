#include <iostream>

int n;
int* arr;

int main() {
	std::cin >> n;

	arr = new int[n];
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	std::cout << arr[n-1] << "\n";
	


	return 0;
}