#include <iostream>
#include <string>

int main() {
	
	int t, point;
	char arr[50] = {'0', };
	std::string str;
	std::cin >> t;
	getchar();


	for (int i = 0; i < t; i++) {
		std::getline(std::cin, str);
		point = -1;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				arr[++point] = '(';
			}
			else {
				point--;
				if (point < -1) {
					break;
				}
			}
		}
		// 스택이 비어있는 경우
		if (point == -1) {
			printf("YES\n");
		}
		// 스택이 비어있지 않은 경우
		else {
			printf("NO\n");
		}
	}
	

	return 0;
}