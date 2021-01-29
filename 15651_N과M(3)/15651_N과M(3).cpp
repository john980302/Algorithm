#include <iostream>
#include <vector>

int n, m;
std::vector<int> v;
bool selected[8];
int arr[8];

void Print() {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}
	std::cout << "\n";
}

void Rec(int cnt) {
	if (cnt == m) {
		Print();
		return;
	}

	for (int i = 0; i < n; i++) {
		selected[i] = true;
		v.push_back(arr[i]);
		Rec(cnt + 1);
		v.pop_back();
		selected[i] = false;
	}
}

int main() {

	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	Rec(0);

	return 0;
}