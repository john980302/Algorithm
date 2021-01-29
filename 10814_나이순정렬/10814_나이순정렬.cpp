#include <iostream>
#include <string>

typedef struct member_ {
	int num;
	int age;
	std::string name;
}member;

int n;
member* arr;
member tmp_arr[100000];


void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i].age < arr[j].age) {
			tmp_arr[k++] = arr[i++];
		}
		else if (arr[i].age == arr[j].age && arr[i].num < arr[j].num) {
			tmp_arr[k++] = arr[i++];
		}
		else {
			tmp_arr[k++] = arr[j++];
		}
	}
	int tmp = i > mid ? j : i;

	while (k <= right) {
		tmp_arr[k++] = arr[tmp++];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = tmp_arr[i];
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
	arr = new member[n];
	for (int i = 0; i < n; i++) {
		arr[i].num = i;
		std::cin >> arr[i].age >> arr[i].name;
	}

	// 정렬 부분
	partition(0, n - 1);

	// 출력 부분
	for (int i = 0; i < n; i++) {
		std::cout << arr[i].age << " " << arr[i].name << "\n";
	}

	return 0;
}