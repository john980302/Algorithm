#include <iostream>

int zero[41], one[41];


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t, n;
	std::cin >> t;

	zero[0] = 1; zero[1] = 0;
	one[0] = 0; one[1] = 1;
	

	for (int i = 0; i < t; i++) {
		std::cin >> n;
		for (int i = 2; i <= n; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
			one[i] = one[i - 1] + one[i - 2];
		}
		std::cout << zero[n] << " " << one[n] << "\n";
	}

	return 0;
}