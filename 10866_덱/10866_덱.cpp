#include <iostream>
#include <string>

const int MAX_SIZE = 1e4;

class Deque {

private:
	int num[MAX_SIZE];
	int front_idx;
	int back_idx;

public:
	Deque();
	void push_front(int x);
	void push_back(int x);
	void pop_front();
	void pop_back();
	int size();
	int empty();
	int front();
	int back();
};

Deque::Deque() {
	front_idx = 0;
	back_idx = 0;
}

void Deque::push_front(int x) {
	num[front_idx] = x;
	front_idx = (front_idx - 1 + MAX_SIZE) % MAX_SIZE;
}

void Deque::push_back(int x) {
	back_idx = (back_idx + 1) % MAX_SIZE;
	num[back_idx] = x;
}

void Deque::pop_front() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		front_idx = (front_idx + 1) % MAX_SIZE;
		printf("%d\n", num[front_idx]);
	}
}

void Deque::pop_back() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", num[back_idx]);
		back_idx = (back_idx - 1 + MAX_SIZE) % MAX_SIZE;
	}
}

int Deque::size() {
	return (back_idx - front_idx + MAX_SIZE) % MAX_SIZE;
}

int Deque::empty() {
	return front_idx == back_idx;
}

int Deque::front() {
	if (empty()) {
		return -1;
	}
	else {
		return num[(front_idx + 1) % MAX_SIZE];
	}
}

int Deque::back() {
	if (empty()) {
		return -1;
	}
	else {
		return num[back_idx];
	}
}

int main() {
	Deque q;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string str;
		int tmp;
		std::cin >> str;
		if (str.compare("push_back") == 0) {
			std::cin >> tmp;
			q.push_back(tmp);
		}
		else if (str.compare("push_front") == 0) {
			std::cin >> tmp;
			q.push_front(tmp);
		}
		else if (str.compare("pop_front") == 0) {
			q.pop_front();
		}
		else if (str.compare("pop_back") == 0) {
			q.pop_back();
		}
		else if (str.compare("size") == 0) {
			printf("%d\n", q.size());
		}
		else if (str.compare("empty") == 0) {
			printf("%d\n", q.empty());
		}
		else if (str.compare("front") == 0) {
			printf("%d\n", q.front());
		}
		else if (str.compare("back") == 0) {
			printf("%d\n", q.back());
		}
	}




	return 0;
}