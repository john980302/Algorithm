#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// º¯¼ö
	int n, tmp, res = 0;
	std::vector<int> p;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		p.push_back(tmp);
	}

	std::sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		res += p[i] * (n - i);
	}

	printf("%d\n", res);
	
	return 0;
}