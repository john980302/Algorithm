#include <iostream>
#include <string>

int main() {
	int point = -1;
	char arr[100] = { '0', };

	while (1) {
		// point 초기화
		point = -1;

		// 문자열을 한 줄씩 입력
		std::string str;
		std::getline(std::cin, str);

		// 종료
		if (str[0] == '.') {
			break;
		}

		// 문자열이 들어온 경우
		for (int i = 0; i < str.size(); i++) {
			// 문자가 '(' 인 경우
			if (str[i] == '(') {
				arr[++point] = '(';
			}
			// 문자가 '['인 경우
			else if (str[i] == '[') {
				arr[++point] = '[';
			}
			// 문자가 ')' 인 경우
			else if (str[i] == ')') {
				if (point <= -1) {
					point--;
					break;
				}
				else {
					if (arr[point] == '(') {
						arr[point--] = '0';
					}
					else {
						break;
					}
				}
			}
			// 문자가 ']' 인 경우
			else if (str[i] == ']') {
				if (point <= -1) {
					point--;
					break;
				}
				else {
					if (arr[point] == '[') {
						arr[point--] = '0';
					}
					else {
						break;
					}
				}
			}
		}

		if (point == -1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}


	return 0;
}