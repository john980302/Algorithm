#include <iostream>

int main() {

	int k, arr[100000] = { 0, }, point = -1, res = 0;
	std::cin >> k;

	for (int i = 0; i < k; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp == 0) {
			point--;
		}
		else {
			arr[++point] = tmp;
		}
	}
	for (int i = 0; i <= point; i++) {
		res += arr[i];
	}

	printf("%d\n", res);


	return 0;
}