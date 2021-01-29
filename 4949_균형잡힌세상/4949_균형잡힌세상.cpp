#include <iostream>
#include <string>

int main() {
	int point = -1;
	char arr[100] = { '0', };

	while (1) {
		// point �ʱ�ȭ
		point = -1;

		// ���ڿ��� �� �پ� �Է�
		std::string str;
		std::getline(std::cin, str);

		// ����
		if (str[0] == '.') {
			break;
		}

		// ���ڿ��� ���� ���
		for (int i = 0; i < str.size(); i++) {
			// ���ڰ� '(' �� ���
			if (str[i] == '(') {
				arr[++point] = '(';
			}
			// ���ڰ� '['�� ���
			else if (str[i] == '[') {
				arr[++point] = '[';
			}
			// ���ڰ� ')' �� ���
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
			// ���ڰ� ']' �� ���
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