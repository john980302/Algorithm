#include <iostream>

typedef struct _point {
	int x;
	int y;
}point;

int n;
point arr[1000001];
point* arr2;

void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i].x < arr[j].x) {
			arr2[k].x = arr[i].x;
			arr2[k++].y = arr[i++].y;
		}
		else if (arr[i].x == arr[j].x && arr[i].y < arr[j].y) {
			arr2[k].x = arr[i].x;
			arr2[k++].y = arr[i++].y;
		}
		else {
			arr2[k].x = arr[j].x;
			arr2[k++].y = arr[j++].y;
		}
			
	}

	int tmp = i > mid ? j : i;

	while (k <= right) {
		arr2[k].x = arr[tmp].x;
		arr2[k++].y = arr[tmp++].y;
	}

	for (int i = left; i <= right; i++) {
		arr[i].x = arr2[i].x;
		arr[i].y = arr2[i].y;
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
	arr2 = new point[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].x >> arr[i].y;
	}

	// 정렬 부분
	partition(0, n - 1);

	// 출력 부분
	for (int i = 0; i < n; i++) {
		std::cout << arr[i].x << " " << arr[i].y << "\n";
	}

	return 0;
}