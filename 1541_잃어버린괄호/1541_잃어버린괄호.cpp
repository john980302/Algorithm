#include <iostream>
#include <vector>
#include <string>


std::string str;
std::vector<std::string> minused_str;
int current = 0, previous = 0, res = 0;

int main() {
	
	// ó�� �Է�
	std::cin >> str;
	
	// ����� ����
	current = str.find('-');
	while (1) {
		// ã�� ���� ���� ��� ����
		if (current == std::string::npos) {
			break;
		}
		// '-'�� �������� ����
		minused_str.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find('-', previous);
	}
	minused_str.push_back(str.substr(previous, current - previous));

	// ���ϱ� ����� �� ��� ����
	for (int i = 0; i < minused_str.size();i++) {
		
		int tmp = 0;
		int idx = minused_str[i].find('+');
		
		// minused_str[i]���� '+'�� �ִ� ���
		if (idx != std::string::npos) {
			previous = 0; current = idx;
			while (1) {
				if (current == std::string::npos) {
					break;
				}
				tmp += stoi(minused_str[i].substr(previous, current - previous));
				previous = current + 1;
				current = minused_str[i].find('+', previous);
			}
			tmp += stoi(minused_str[i].substr(previous, current - previous));
		}
		// minused_str[i]���� '+'�� ���� ���
		else {
			tmp = stoi(minused_str[i]);
		}

		// �� ó���� ���
		if (i == 0) {
			res = tmp;
		}
		// �� ó���� �ƴ� ���
		else {
			res -= tmp;
		}
	}

	printf("%d\n", res);

	return 0;
}