#include <iostream>
#include <cstdlib>

int main()
{
	int n;
	std::cin >> n;

	int rm = 0;
	for (int m = 0; m < n; m++) {
		int tm = m;
		int s = 0;
		s += tm;
		while (1) {
			s += tm % 10;
			if (tm / 10 == 0) {
				break;
			}
			tm /= 10;
		}
		if (n == s) {
			rm = m;
			break;
		}
	}
	std::cout << rm << std::endl;
	return 0;
}