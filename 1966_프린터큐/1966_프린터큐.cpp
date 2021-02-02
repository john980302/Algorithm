#include <iostream>
#include <deque>



int main() {

	int t, n, m, tmp;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		std::deque<std::pair<int, int>> q;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			q.push_back(std::make_pair(j, tmp));
		}

		//printf("-------------------------------\n");
		int first_point = 0, other_point = 1, cnt = 1;
		while (1) {
			/*
			// 출력 테스트
			for (int j = 0; j < n; j++) {
				printf("%d ", q[j].second);
			}
			printf("\n");
			*/
			
			// deque의 사이즈가 1개일 경우
			if (first_point == q.size() - 1) {
				if (q[first_point].first == m) {
					printf("%d\n", cnt);
				}
				break;
			}
			
			if (q[first_point].second < q[other_point].second) {
				q.push_back(q[first_point]);
				q.pop_front();
				other_point = 1;
			}
			else {
				if (other_point >= n - 1) {
					if (q[first_point].first == m) {
						printf("%d\n", cnt);
						break;
					}
					else {
						q.pop_front();
						cnt++;
						other_point = 1;
						n--;
					}
				}
				else {
					other_point++;
				}
			}
		}
		//printf("-------------------------------\n");

	}



	return 0;
}