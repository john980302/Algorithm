#include <iostream>
#include <string>

int main() {

	int stack[10000], n, point = -1;
	std::string inp;
	std::cin >> n;
	getchar();

	for (int i = 0; i < n; i++) {
		getline(std::cin, inp);
		auto it = inp.find("push");

		if (it != std::string::npos) {
			stack[++point] = stoi(inp.substr(5, std::string::npos));
		}
		else {
			if (inp.compare("top") == 0) {
				if (point == -1) {
					printf("%d\n", point);
				}
				else {
					printf("%d\n", stack[point]);
				}
			}
			else if (inp.compare("size") == 0) {
				printf("%d\n", point + 1);
			}
			else if (inp.compare("empty") == 0) {
				if (point == -1) {
					printf("%d\n", 1);
				}
				else {
					printf("%d\n", 0);
				}
			}
			else if (inp.compare("pop") == 0) {
				if (point == -1) {
					printf("%d\n", point);
				}
				else {
					printf("%d\n", stack[point--]);
				}
			}

		}

	}


	return 0;
}