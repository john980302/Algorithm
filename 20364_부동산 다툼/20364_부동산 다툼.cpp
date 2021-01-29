#include <iostream>

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	int* arr = new int[n];
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);

		int tt = t;
		int flag = 0;

		while (t) {
			if (arr[t])
				flag = t;
			t /= 2;
		}

		if (flag) printf("%d\n", flag);
		else printf("0\n"), arr[tt] = 1;

	}
}