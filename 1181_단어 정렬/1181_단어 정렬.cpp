#include <iostream>
#include <string>

int n;
std::string arr[20000];
std::string* arr2;

void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i].size() < arr[j].size()) {
			arr2[k++] = arr[i++];
		}
		else if (arr[i].size() == arr[j].size() && arr[i] < arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}

	int tmp = i > mid ? j : i;

	while (k <= right) {
		arr2[k++] = arr[tmp++];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void partition(int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}
int main() {

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);

	// 입력 받는 부분
	std::cin >> n;
	arr2 = new std::string [n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	// 정렬 부분
	partition(0, n - 1);

	// 출력 부분
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			std::cout << arr[i] << "\n";
		}
		else if (arr[i] != arr[i - 1]) {
			std::cout << arr[i] << "\n";
		}
	}

	return 0;
}



