#include <iostream>

int gcd(int a, int b) {
	int r = 0;
	if (a < b) {
		r = a;
		a = b;
		b = r;
	}
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	else {
		return (-a);
	}
}

int gcdlist(int* arr, int n) {
	int g = arr[0];
	for (int i = 1; i < n; i++) {
		g = gcd(arr[i], g);
	}
	return g;
}

int main() {
	int n;
	std::cin >> n;
	int arr[99];
	int tmp;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		if (i != 0)
		{
			arr[i - 1] = abs(a - tmp);
		}
		tmp = a;
	}
	int g = gcdlist(arr, n - 1);
	for (int i = 2; i <= g/2; i++)
	{
		if (g % i == 0)
		{
			std::cout << i << " ";
		}
	}
	std::cout << g << std::endl;

	return 0;
}