#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> ans;
	std::vector<std::pair<int, int>> stack;
	std::cin >> n;

	// �Է�
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		ans.push_back(tmp);
	}

	// ó�� ���� ������ �Է�
	stack.push_back(std::make_pair(0, ans[0]));

	// ���
	for (int i = 1; i < n; i++) {
		while (!stack.empty() && ans[i] > stack.back().second) {
			ans[stack.back().first] = ans[i];
			stack.pop_back();
		}
		stack.push_back(std::make_pair(i, ans[i]));
	}
	while (!stack.empty()) {
		ans[stack.back().first] = -1;
		stack.pop_back();
	}

	// ���
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	

	return 0;
}