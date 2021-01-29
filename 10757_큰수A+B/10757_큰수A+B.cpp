#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
	// 변수
	std::string a, b;
	std::vector<char> c;
	int len, tmp = 0;

	// 입력
	std::cin >> a >> b;
	len = std::min(a.size(), b.size());
	for (int i = 1; i <= len; i++) {
		tmp += int(a[a.size()-i] - '0') + int(b[b.size()-i] - '0');
		if (tmp > 9) {
			c.push_back(char(tmp - 10 + '0'));
			tmp = 1;
		}
		else {
			c.push_back(char(tmp + '0'));
			tmp = 0;
		}
	}

	if (a.size() > b.size()) {
		for (int i = a.size() - len - 1; i >= 0; i--) {
			tmp += int(a[i] - '0');
			if (tmp > 9) {
				c.push_back(char(tmp - 10 + '0'));
				tmp = 1;
			}
			else {
				c.push_back(char(tmp + '0'));
				tmp = 0;
			}
		}
		if (tmp == 1) {
			c.push_back(char(tmp + '0'));
		}
	}
	else if (b.size() > a.size()) {
		for (int i = b.size() - len - 1; i >= 0; i--) {
			tmp += int(b[i] - '0');
			if (tmp > 9) {
				c.push_back(char(tmp - 10 + '0'));
				tmp = 1;
			}
			else {
				c.push_back(char(tmp + '0'));
				tmp = 0;
			}
		}
		if (tmp == 1) {
			c.push_back(char(tmp + '0'));
		}
	}
	else {
		if (tmp == 1) {
			c.push_back(char(tmp + '0'));
		}
	}


	for (auto iter = c.rbegin(); iter != c.rend(); ++iter) {
		std::cout << *iter;
	}
	std::cout << "\n";
	
	return 0;
}