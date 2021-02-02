#include <iostream>
#include <deque>
#include <vector>

std::deque<std::pair<int, int>> q;
std::vector<int> v;

int main() {

	int n, k, idx, cnt;
	scanf_s("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		q.push_back(std::make_pair(0, i));
	}
	
	idx = 0;
	cnt = 1;
	while (v.size() != n) {
		if (q[idx].first == 0) {
			if (cnt == k) {
				v.push_back(q[idx].second);
				q[idx].first = 1;
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		idx++;
		if (idx >= n) {
			idx = 0;
		}
	}
	printf("<");
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			printf("%d", v[i]);
		}
		else {
			printf("%d, ", v[i]);
		}
	}
	printf(">\n");


	


	return 0;
}