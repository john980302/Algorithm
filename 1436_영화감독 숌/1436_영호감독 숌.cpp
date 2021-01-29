#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int cnt = 0;
	int num = 666;

	while (cnt < n) {
		int cp[10] = { 0, }; // cp가 3인 경우 666
		int tnum = num;
		int ii = 9;
		while (1) {
			if (tnum % 10 == 6) {
				cp[ii]++;
			}
			if (tnum / 10 == 0) {
				break;
			}
			ii--;
			tnum /= 10;
		}
		for (int i = 9; i >= 2; i--) {
			if (cp[i] == 1 && cp[i - 1] == 1 && cp[i - 2] == 1) {
				cnt++;
				break;
			}
		}
		num++;
	}
	std::cout << --num << std::endl;
	
		
	return 0;
}