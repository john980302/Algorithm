#include <iostream>
#include <vector>

std::vector<int> num_arr;
std::vector<char> plus_minus_arr;

int main() {
	int n, inp = 1, cnk = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;

		// push
		while (tmp >= inp) {
			num_arr.push_back(inp++);
			plus_minus_arr.push_back('+');
		}
		
		// pop
		if (num_arr[num_arr.size() - 1] == tmp) {
			num_arr.pop_back();
			plus_minus_arr.push_back('-');
		}
		else {
			cnk = 1;
		}
	}

	if (cnk == 1) {
		printf("NO\n");
	}
	else {
		for (int i = 0; i < plus_minus_arr.size(); i++) {
			printf("%c\n", plus_minus_arr[i]);
		}
	}
	

	return 0;
}