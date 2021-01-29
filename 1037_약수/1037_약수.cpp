#include <iostream>

int num, arr[50];

void sort() {
	for (int i = 0; i < num; i++) {
		for (int j = i+1; j < num; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int main() {
	
	std::cin >> num;
	for (int i = 0; i < num; i++) {
		std::cin >> arr[i];
	}
	sort();
	if (num == 1) {
		printf("%d\n", arr[0] * arr[0]);
	}
	else if (num >= 2) {
		printf("%d\n", arr[0] * arr[num - 1]);
	}

	return 0;
}