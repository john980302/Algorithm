#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// 전역변수
int n;
int operator_[4];
std::vector<int> arr(11, 0);
std::vector<int> oper;
int res, res_min, res_max;

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
	res = arr[0];
	for (int i = 0; i < oper.size(); i++) {
		switch (oper[i])
		{
		case 0:
			res += arr[i + 1];
			break;
		case 1:
			res -= arr[i + 1];
			break;
		case 2:
			res *= arr[i + 1];
			break;
		case 3:
			res /= arr[i + 1];
			break;
		default:
			break;
		}
	}
}

void Rec() {
	bool check = false;
	int  down_bia = 0;

	for (int i = 0; i < 4; i++) {
		if (operator_[0] + operator_[1] + operator_[2] + operator_[3] == 0) {
			cal();
			if (res > res_max)
				res_max = res;
			if (res < res_min)
				res_min = res;
			return;
		}
		if (operator_[i] != 0) {
			operator_[i]--;
			check = true;
		}
		else {
			continue;
		}
		oper.push_back(i);
		Rec();
		
		if (check) {
			operator_[i]++;
			check = false;
		}
		oper.pop_back();
		
	}
}


int main() {

	// 입력 부분
	std::cin >> n;
	std::cin.ignore();

	std::string str;
	std::getline(std::cin, str);

	std::vector<std::string> line_vector = split(str, ' ');
	
	for (int i = 0; i < line_vector.size(); ++i) {
		arr[i] = std::stoi(line_vector[i]);
	}

	std::getline(std::cin, str);
	line_vector = split(str, ' ');

	for (int i = 0; i < line_vector.size(); ++i) {
		operator_[i] = std::stoi(line_vector[i]);
	}

	
	res_min = 1000000000;
	res_max = -1000000000;

	Rec();
	
	printf("%d\n%d\n", res_max, res_min);

	return 0;
}