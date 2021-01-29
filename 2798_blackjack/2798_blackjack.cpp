#include <iostream>
#include <algorithm>

int main()
{
	// n, m 입력
	int n, m;
	std::cin >> n >> m;

	// n개의 숫자 저장
	int* num_str = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> *(num_str + i);
	}
	// 정렬
	std::sort(num_str, num_str + n);

	// m과 제일 가까운 합계
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