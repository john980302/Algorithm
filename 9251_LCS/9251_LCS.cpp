#include <iostream>

int main() {
	char str1[1001], str2[1001];
	int dp[1001];
	std::cin >> str1;
	std::cin >> str2;
	for (int i = 0; i < strlen(str1); i++) {
		printf("%c ", str1[i]);
	}
	printf("\n");
	for (int i = 0; i < strlen(str2); i++) {
		printf("%c ", str2[i]);
	}
	printf("\n");
	/*
	// ����
	// str1: AD 
	// str2: ABCED
	// str1���� A�� str2�� �����ϸ� str2���� B~D���̿� str1�� D�� �����ϴ� �� Ȯ���ϴ� ������ �˰����� ����
	*/
	for (int i = 0; i < 1001; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {

		}
	}

	
	return 0;
}