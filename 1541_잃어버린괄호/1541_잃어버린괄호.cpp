#include <iostream>
#include <vector>
#include <string>


std::string str;
std::vector<std::string> minused_str;
int current = 0, previous = 0, res = 0;

int main() {
	
	// 처음 입력
	std::cin >> str;
	
	// 빼기로 분할
	current = str.find('-');
	while (1) {
		// 찾는 값이 없는 경우 종료
		if (current == std::string::npos) {
			break;
		}
		// '-'을 기준으로 분할
		minused_str.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find('-', previous);
	}
	minused_str.push_back(str.substr(previous, current - previous));

	// 더하기 계산한 후 모두 빼기
	for (int i = 0; i < minused_str.size();i++) {
		
		int tmp = 0;
		int idx = minused_str[i].find('+');
		
		// minused_str[i]에서 '+'가 있는 경우
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
		// minused_str[i]에서 '+'가 없는 경우
		else {
			tmp = stoi(minused_str[i]);
		}

		// 맨 처음인 경우
		if (i == 0) {
			res = tmp;
		}
		// 맨 처음이 아닌 경우
		else {
			res -= tmp;
		}
	}

	printf("%d\n", res);

	return 0;
}