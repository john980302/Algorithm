#include <iostream>
#include <algorithm>

int main()
{
	// n, m �Է�
	int n, m;
	std::cin >> n >> m;

	// n���� ���� ����
	int* num_str = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> *(num_str + i);
	}
	// ����
	std::sort(num_str, num_str + n);

	// m�� ���� ����� �հ�
	int rs = 0;
	
	for (int i = n - 1; i >= 2; i--) {
		int s = 0;
		s += num_str[i];
		for (int j = i - 1; j >= 1; j--) {
			s += num_str[j];
			for (int k = j - 1; k >= 0; k--) {
				s += num_str[k];
				if (s > m) {
					s -= num_str[k];
				}
				else if (s == m){
					rs = m;
					break;
				}
				else {
					if (rs < s) {
						rs = s;
					}
					s -= num_str[k];
				}
			}
			if (rs == m) {
				break;
			}
			else {
				s -= num_str[j];
			}
		}
		if (rs == m) {
			break;
		}
	}
	std::cout << rs << std::endl;
	
	return 0;
}