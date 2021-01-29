#include <iostream>

int main() {
	int n, res = 1;
	char s[100][101] = { 'a', };

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][0] != s[j][strlen(s[j]) - 1]) {
				res = 0;
				printf("%d\n", res);
				return 0;
			}
			if (s[i][strlen(s[i]) - 1] != s[j][0]) {
				res = 0;
				printf("%d\n", res);
				return 0;
			}
		}
	}
	printf("%d\n", res);


	return 0;
}