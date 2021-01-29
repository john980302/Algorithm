#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// 전역변수
int n, end, t_min, start_team, link_team;
std::vector<std::vector<int>> arr;
std::vector<int> start_arr;
std::vector<int> link_arr;


std::vector<std::string> split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string temp;

	while (std::getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}
	return internal;
}

void cal() {
	start_team = 0, link_team = 0;
	link_arr.clear();
	// link_team 초기화
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (k >= start_arr.size()) {
			link_arr.push_back(i);
		}
		else {
			if (i != start_arr[k]) {
				link_arr.push_back(i);
			}
			else {
				k++;
			}
		}
	}
	// start_team score 계산
	for (int i = 0; i < start_arr.size(); i++) {
		for (int j = 0; j < start_arr.size(); j++) {
			if (start_arr[i] != start_arr[j]) {
				start_team += arr[start_arr[i] - 1][start_arr[j] - 1];
			}
		}
	}
	// link_team score 계산
	for (int i = 0; i < link_arr.size(); i++) {
		for (int j = 0; j < link_arr.size(); j++) {
			if (link_arr[i] != link_arr[j]) {
				link_team += arr[link_arr[i] - 1][link_arr[j] - 1];
			}
		}
	}
	
}

void Rec(int cnt) {

	for (int i = 1; i <= n; i++) {
		if (cnt == n / 2) {
			cal();
			if (t_min > abs(start_team - link_team))
				t_min = abs(start_team - link_team);
			return;
		}
		if (!start_arr.empty()) {
			if (start_arr.back() >= i) {
				continue;
			}
		}
		start_arr.push_back(i);
		Rec(cnt + 1);
		start_arr.pop_back();

		
	}
	
}


int main() {

	// 입력 부분
	std::cin >> n;
	std::cin.ignore();

	std::string str;
	std::vector<std::string> line_vector;

	for (int i = 0; i < n; i++) {
		std::getline(std::cin, str);

		line_vector = split(str, ' ');

		std::vector<int> tmp(n,0);

		for (int i = 0; i < line_vector.size(); ++i) {
			tmp[i] = std::stoi(line_vector[i]);
		}
		arr.push_back(tmp);
	}
	end = 1;
	for (int i = n; i > n / 2; i--) {
		end *= i;
	}
	for (int i = 0; i < n / 2; i++) {
		end /= (i + 1);
	}
	
	t_min = 100;

	Rec(0);

	printf("%d\n", t_min);

	return 0;
}