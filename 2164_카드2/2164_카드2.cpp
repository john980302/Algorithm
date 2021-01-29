#include <iostream>
#include <queue>

std::queue<int> q;

int main() {
	int n, tmp = 0;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() > 1) {
		tmp++;
		if (tmp % 2 == 1) {
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	printf("%d\n", q.front());



	return 0;
}