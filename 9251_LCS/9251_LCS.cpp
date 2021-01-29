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
	// 예시
	// str1: AD 
	// str2: ABCED
	// str1에서 A가 str2에 존재하면 str2에서 B~D사이에 str1의 D가 존재하는 지 확인하는 식으로 알고리즘을 구현
	*/
	for (int i = 0; i < 1001; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {

		}
	}

	
	return 0;
}