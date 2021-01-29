#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector< std::pair<int, int> > v;
// ȸ�ǰ� ������ �ð��� �������� �������� ����
bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}


int main() {
	
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		std::cin >> start >> end;
		v.push_back(std::make_pair(start, end));
	}

	sort(v.begin(), v.end(), compare);

	int time = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (time <= v[i].first) {
			time = v[i].second;
			cnt++;
		}
	}

	std::cout << cnt;

	return 0;
}