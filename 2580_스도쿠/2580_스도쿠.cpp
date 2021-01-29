#include <iostream>

int inp[9][9];

bool check(int x, int y, int t) {
	int x_box = x / 3 * 3;
	int y_box = y / 3 * 3;
	
	for (int i = 0; i < 9; i++) {
		// ���� Ȯ��
		if (inp[x][i] == t) {
			return false;
		}
		// ���� Ȯ��
		if (inp[i][y] == t) {
			return false;
		}
		// ���� Ȯ��
		if (inp[x_box + i / 3][y_box + i % 3] == t) {
			return false;
		}
	}
	return true;
}


void solve(int x, int y, int zerocnt, int cnt) {

	// �־���ϴ� ���� ��� ���� ���.
	if (cnt == zerocnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << inp[i][j] << " ";
			}
			std::cout << "\n";
		}
		// ����Ŀ� ���α׷� ����
		exit(0);
	}

	// ���� ĭ�� ����ִ� ���
	if (inp[x][y] == 0) {
		// t�� x, y ��ġ�� �ֱ�
		for (int t = 1; t <= 9; t++) {
			// x, y, ��ġ���� t Ȯ��(����, ����, ����)
			if (check(x, y, t)) {
				inp[x][y] = t;
				// y�� �켱������ Ű���.
				if (y < 8) {
					solve(x, y + 1, zerocnt, cnt + 1);
				}
				// x�� Ű���.
				else {
					solve(x + 1, 0, zerocnt, cnt + 1);
				}
				
				inp[x][y] = 0;
			}
		}
	}
	else {
		// y�� �켱������ Ű���.
		if (y < 8) {
			solve(x, y + 1, zerocnt, cnt);
		}
		// x�� Ű���.
		else {
			solve(x + 1, 0, zerocnt, cnt);
		}
	}

}

int main() {
	// ����
	int zerocnt = 0;

	// �Է�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> inp[i][j];
			// ��ĭ ���� ����
			if (inp[i][j] == 0) {
				zerocnt++;
			}
		}
	}

	// ���
	solve(0, 0, zerocnt, 0);
	

	return 0;
}