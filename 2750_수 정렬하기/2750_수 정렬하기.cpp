#include <iostream>

int main() {

	// ������ ����
	int n;
	std::cin >> n;

	// ������ ���� �Է� �ޱ�
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	// ����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// ���
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}