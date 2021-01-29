#include <iostream>

int inp[9][9];

bool check(int x, int y, int t) {
	int x_box = x / 3 * 3;
	int y_box = y / 3 * 3;
	
	for (int i = 0; i < 9; i++) {
		// 가로 확인
		if (inp[x][i] == t) {
			return false;
		}
		// 세로 확인
		if (inp[i][y] == t) {
			return false;
		}
		// 상자 확인
		if (inp[x_box + i / 3][y_box + i % 3] == t) {
			return false;
		}
	}
	return true;
}


void solve(int x, int y, int zerocnt, int cnt) {

	// 넣어야하는 곳에 모두 넣은 경우.
	if (cnt == zerocnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << inp[i][j] << " ";
			}
			std::cout << "\n";
		}
		// 출력후에 프로그램 종료
		exit(0);
	}

	// 만일 칸이 비어있는 경우
	if (inp[x][y] == 0) {
		// t를 x, y 위치에 넣기
		for (int t = 1; t <= 9; t++) {
			// x, y, 위치에서 t 확인(가로, 세로, 상자)
			if (check(x, y, t)) {
				inp[x][y] = t;
				// y를 우선적으로 키운다.
				if (y < 8) {
					solve(x, y + 1, zerocnt, cnt + 1);
				}
				// x를 키운다.
				else {
					solve(x + 1, 0, zerocnt, cnt + 1);
				}
				
				inp[x][y] = 0;
			}
		}
	}
	else {
		// y를 우선적으로 키운다.
		if (y < 8) {
			solve(x, y + 1, zerocnt, cnt);
		}
		// x를 키운다.
		else {
			solve(x + 1, 0, zerocnt, cnt);
		}
	}

}

int main() {
	// 변수
	int zerocnt = 0;

	// 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> inp[i][j];
			// 빈칸 개수 측정
			if (inp[i][j] == 0) {
				zerocnt++;
			}
		}
	}

	// 계산
	solve(0, 0, zerocnt, 0);
	

	return 0;
}