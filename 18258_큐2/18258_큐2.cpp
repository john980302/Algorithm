#include <iostream>
#include <queue>
#include <string>

std::queue<int> q;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	/*
	int n, val;
	std::string str;
	std::cin >> n;
	

	for (int i = 0; i < n; i++) {
		std::cin >> str;

		// push
		if (str.compare("push") == 0) {
			std::cin >> val;
			q.push(val);
		}

		// pop
		else if (str.compare("pop") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.front();
				q.pop();
			}
			printf("%d\n", val);
		}

		// size
		else if (str.compare("size") == 0) {
			printf("%d\n", q.size());
		}

		// empty
		else if (str.compare("empty") == 0) {
			printf("%d\n", q.empty());
		}

		// front
		else if (str.compare("front") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.front();
			}
			printf("%d\n", val);
		}

		// back
		else if (str.compare("back") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.back();
			}
			printf("%d\n", val);
		}
	}
	*/

	int n, val;
	std::string str;
	std::cin >> n;
	getchar();

	for (int i = 0; i < n; i++) {
		std::getline(std::cin, str, '\n');

		// pop
		if (str.compare("pop ") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.front();
				q.pop();
			}
			printf("%d\n", val);
		}

		// size
		else if (str.compare("size ") == 0) {
			printf("%d\n", q.size());
		}

		// empty
		else if (str.compare("empty ") == 0) {
			printf("%d\n", q.empty());
		}

		// front
		else if (str.compare("front ") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.front();
			}
			printf("%d\n", val);
		}

		// back
		else if (str.compare("back ") == 0) {
			if (q.empty()) {
				val = -1;
			}
			else {
				val = q.back();
			}
			printf("%d\n", val);
		}

		else {
			val = std::stoi(str.substr(5));
			q.push(val);
		}
	}

	return 0;
}