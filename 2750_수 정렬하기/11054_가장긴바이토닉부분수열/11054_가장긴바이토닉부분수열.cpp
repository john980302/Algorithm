#include <iostream>
#include <algorithm>

int main() {
	// 변수 설정 및 입력
	int n, udp_max, ddp_max, ans_max = 0;
	int arr[1000], udp[1000], ddp[1000], ans[1000];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	
	// 오름차순의 마지막 수를 i로 생각
	for (int i = 0; i < n; i++) {
		// udp와 ddp 값과 최대값을 각각 1과 0으로 초기화
		for (int k = 0; k < n; k++) {
			udp[k] = 1;
			ddp[k] = 1;
		}
		udp_max = 0;
		ddp_max = 0;

		// i번째까지 오름차순으로 제일 큰 값을 구함.
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= j; k++) {
				if (arr[j] > arr[k] && udp[k] + 1 > udp[j]) {
					udp[j] = udp[k] + 1;
				}
			}
		}
		for (int j = 0; j <= i; j++) {
			udp_max = std::max(udp_max, udp[j]);
		}

		// i ~ 끝까지 내림차순으로 제일 큰 값을 구함.
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				if (arr[j] < arr[k] && ddp[k] + 1 > ddp[j]) {
					ddp[j] = ddp[k] + 1;
				}
			}
		}
		for (int j = i; j < n; j++) {
			ddp_max = std::max(ddp_max, ddp[j]);
		}

		// i가 0일때부터 n-1일때까지 저장한 값들을 입력하는 곳.
		ans[i] = udp_max + ddp_max - 1;

		// 가장 긴 바이토닉수열 찾기
		ans_max = std::max(ans[i], ans_max);

	}
	
	std::cout << ans_max;
	
	return 0;
}