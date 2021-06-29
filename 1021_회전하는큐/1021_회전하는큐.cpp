#include <iostream>

typedef struct node_ {
	int num;
	struct node_* pre;
	struct node_* next;
}node;

class Queue {

private:
	node* head;
	node* tail;
	node* newNode;
	int n;

public:
	Queue(int n);
	void one();
	void two();
	void three();
	void print();
	int get_head();
	int small(int a);
};

Queue::Queue(int n_) {
	n = n_;
	head = NULL;
	tail = NULL;
	newNode = NULL;
	for (int i = 0; i < n; i++) {
		newNode = new node();
		newNode->num = (i + 1);
		newNode->pre = tail;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
	}
	tail->next = head;
	head->pre = tail;
}

void Queue::one() {
	node* delNode = head;
	head = delNode->next;
	if (head == tail) {
		return;
	}
	else {
		head->pre = tail;
		tail->next = head;
	}
	free(delNode);
	n--;
}

void Queue::two() {
	tail = head;
	head = tail->next;
}

void Queue::three() {
	head = tail;
	tail = head->pre;
	
}

void Queue::print() {
	printf("size: %d = ", n);
	node* cur = head;
	while (1) {
		printf("%d ", cur->num);
		if (cur == tail) {
			break;
		}
		cur = cur->next;
	}
	printf("\n");
}

int Queue::small(int a) {
	int b = n - a;
	return a > b ? b : a;
}

int Queue::get_head() {
	return head->num;
}

int main() {
	int n, m, res = 0;
	std::cin >> n >> m;

	Queue q(n);
	for (int i = 0; i < m; i++) {
		int inp, tmp;
		std::cin >> inp;
		// one
		if (q.get_head() == inp) {
			q.one();
		}
		else {
			tmp = 0;
			while (1) {
				//q.print();
				if (inp == q.get_head()) {
					res += q.small(tmp);
					q.one();
					break;
				}
				q.two();
				tmp++;
			}
		}
	}

	// print answer
	printf("%d\n", res);

	return 0;
}