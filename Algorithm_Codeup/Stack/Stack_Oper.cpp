#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main() {
	stack<int> nums;
	int fir, sec, result = 0;
	string s, buf;
	getline(cin, s);
	stringstream ss(s);
	while (ss >> buf) {
		if (buf == "+") {
			sec = nums.top();
			nums.pop();
			fir = nums.top();
			nums.pop();
			nums.push(fir + sec);
		}
		else if (buf == "*") {
			sec = nums.top();
			nums.pop();
			fir = nums.top();
			nums.pop();
			nums.push(fir * sec);
		}
		else if (buf == "-") {
			sec = nums.top();
			nums.pop();
			fir = nums.top();
			nums.pop();
			nums.push(fir - sec);
		}
		else nums.push(stoi(buf));
	}
	cout << nums.top();
}
