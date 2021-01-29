#include <iostream>
#include <algorithm>

int main() {
	// ���� ���� �� �Է�
	int n, udp_max, ddp_max, ans_max = 0;
	int arr[1000], udp[1000], ddp[1000], ans[1000];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	
	// ���������� ������ ���� i�� ����
	for (int i = 0; i < n; i++) {
		// udp�� ddp ���� �ִ밪�� ���� 1�� 0���� �ʱ�ȭ
		for (int k = 0; k < n; k++) {
			udp[k] = 1;
			ddp[k] = 1;
		}
		udp_max = 0;
		ddp_max = 0;

		// i��°���� ������������ ���� ū ���� ����.
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

		// i ~ ������ ������������ ���� ū ���� ����.
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

		// i�� 0�϶����� n-1�϶����� ������ ������ �Է��ϴ� ��.
		ans[i] = udp_max + ddp_max - 1;

		// ���� �� ������м��� ã��
		ans_max = std::max(ans[i], ans_max);

	}
	
	std::cout << ans_max;
	
	return 0;
}