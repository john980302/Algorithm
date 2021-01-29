#include <iostream>

long long int factorial(int a) {
	long long int res = 1;
	for (long long int i = a; i > 0; i--) {
		res *= i;
		res %= 10007;
	}
	return res;
}

long long int mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main() {
	int n, k;
	long long res = 1, n_fac = 1, k_nk_fac = 1;
	std::cin >> n >> k;

	if (0 <= k && n >= k) {
		n_fac = factorial(n);
		k_nk_fac = factorial(k) * factorial(n - k) % 10007;
		res = mul(k_nk_fac, 10007 - 2, 10007);
		res %= 10007;
		res *= n_fac;
		res %= 10007;
	}
	
	printf("%lld\n", res);
	return 0;

}