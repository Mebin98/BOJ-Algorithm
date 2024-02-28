#include <iostream>
#include <vector>

using namespace std;

/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/

vector<string>pw;

void input() {
	string input;
	while (true) {
		cin >> input;
		if (input == "end") break;
		pw.push_back(input);
	}
}

string inspect(string pwd) {
	bool vowel = false; // 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
	bool notThree = true; // 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
	bool notSameTwo = true; // 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

	for (int i = 0; i < pwd.size(); i++) {
		if ((pwd[i] == 'a') || (pwd[i] == 'e') || (pwd[i] == 'i') ||
			(pwd[i] == 'o') || (pwd[i] == 'u')) {
			vowel = true;
		}
	}

	int vNum = 0; int cNum = 0;
	bool v = false; bool c = false;
	for (int i = 0; i < pwd.size(); i++) {
		if (i == 0) {
			if ((pwd[i] == 'a') || (pwd[i] == 'e') || (pwd[i] == 'i') ||
				(pwd[i] == 'o') || (pwd[i] == 'u')) {
				v = true; vNum += 1;
				c = false;
			}
			else {
				v = false;
				c = true; cNum += 1;
			}
		}
		else {
			if (v) { // 전 글자가 모음일때
				if ((pwd[i] == 'a') || (pwd[i] == 'e') || (pwd[i] == 'i') ||
					(pwd[i] == 'o') || (pwd[i] == 'u')) { // 또 모음이면
					vNum += 1;
				}
				else { // 바뀌면
					vNum = 0; cNum = 1;
					v = false; c = true;
				}
			}
			else { // 전 글자가 자음일 때
				if (!((pwd[i] == 'a') || (pwd[i] == 'e') || (pwd[i] == 'i') ||
					(pwd[i] == 'o') || (pwd[i] == 'u'))) { // 또 자음이면
					cNum += 1;
				}
				else { // 바뀌면
					cNum = 0; vNum = 1;
					v = true; c = false;
				}
			}
		}

		if ((vNum >= 3) || (cNum >= 3)) {
			notThree = false;
			break;
		}
	}

	char prev = pwd[0];
	for (int i = 1; i < pwd.size(); i++) {
		if (prev == pwd[i]) {
			if (!(prev == 'e' || prev == 'o')) {
				notSameTwo = false;
			}
		}
		prev = pwd[i];
	}

	if (vowel && notThree && notSameTwo) {
		return "<" + pwd + ">" + " is acceptable.";
	}
	else {
		return "<" + pwd + ">" + " is not acceptable.";
	}

}

void simulate() {
	for (int i = 0; i < pw.size(); i++) {
		cout << inspect(pw[i]) << "\n";
	}
}

int main() {
	input();
	simulate();
	return 0;
}