#include <iostream>

int main()
{
	char n[11] = { 0, };
	std::cin >> n;

	for (int i = 0; i < 11; i++) {
		for (int j = i; j < 11; j++) {
			if (n[i] < n[j]) {
				char t = n[i];
				n[i] = n[j];
				n[j] = t;
			}
		}
	}

	std::cout << atoi(n) << "\n";



	return 0;
}