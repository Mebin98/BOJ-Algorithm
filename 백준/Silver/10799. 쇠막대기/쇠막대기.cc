#define MAX 100000
#include <iostream>
#include <string>

using namespace std;

struct Stack {
	char stack[MAX];
	int top;

	Stack() : top(-1) {} // initially, top = -1;

	bool isFull() {
		if (top == MAX) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(char ch) { // push element
		if (top < MAX - 1) {
			stack[++top] = ch;
		}
		else if(isFull()){
			cout << "Stack Overflow Warning\n";
		}
	}

	char pop() { // pop element
		if (top >= 0) {
			return stack[top--];
		}
		else if(isEmpty()){
			cout << "Stack Underflow Warning\n";
			return -1;
		}
	}
};

int Solve() { // Start Program
	string str;
	cin >> str;

	Stack myStack;
	int ans = 0; // answer variable
	int metal = 0; // when laser evokes, sum metal

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			myStack.push(str[i]);
			ans += 1;
			metal += 1;
		}
		else {
			if (str[i-1] == '(') { // Laser Case
				myStack.pop(); 
				metal -= 1;
				ans -= 1;
				if (metal >= 1) ans += metal;
			}
			else {
				myStack.pop();
				metal -= 1;
			}
		}
	}
	return ans;
}

int main() {
	int ans = Solve();
	cout << ans << "\n";
	return 0;
}