#include <iostream>

struct info
{
	int w;	// 몸무게
	int h;	// 키
	int rank; // 등수
};

int main()
{
	int n;
	std::cin >> n;

	info* people = new info[n];
	for (int i = 0; i < n; i++) {
		std::cin >> people[i].w >> people[i].h;
		people[i].rank = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (people[i].w < people[j].w && people[i].h < people[j].h) {
				people[i].rank++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << people[i].rank << " ";
	}
	return 0;
}