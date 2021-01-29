#include <iostream>

int smaller3(int a, int b, int c) {
	return (a <= b && a <= c) ? a : ((b <= a && b <= c) ? b : c);
}

int smaller2(int a, int b) {
	return a <= b ? a : b;
}

int n;
int arr[1000000];

int main() {
	
	std::cin >> n;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 != 0 && i % 2 != 0) {
			arr[i] = arr[i - 1] + 1;
		}
		else if (i % 3 == 0 && i % 2 != 0) {
			arr[i] = smaller2(arr[i / 3] + 1, arr[i - 1] + 1);
		}
		else if (i % 3 != 0 && i % 2 == 0){
			arr[i] = smaller2(arr[i / 2] + 1, arr[i - 1] + 1);
		}
		else {
			arr[i] = smaller3(arr[i - 1] + 1, arr[i / 2] + 1, arr[i / 3] + 1);
		}
	}

	std::cout << arr[n] << "\n";


	return 0;
}