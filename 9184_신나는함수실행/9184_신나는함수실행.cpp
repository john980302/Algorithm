#include <iostream>

int check[21][21][21];

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (check[a][b][c] > 0) {
		return check[a][b][c];
	}
	if (a < b && b < c) {
		check[a][b][c] =  w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		check[a][b][c] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return check[a][b][c];
}


int main() {
	int a, b, c;
	
	while (1) {
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		else if (a <= 0 || b <= 0 || c <= 0) {
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
			continue;
		}
		else if (a > 20 || b > 20 || c > 20) {
			printf("w(%d, %d, %d) = %d\n", a, b, c, w(20, 20, 20));
			continue;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
		
	}
	
	


	return 0;
}