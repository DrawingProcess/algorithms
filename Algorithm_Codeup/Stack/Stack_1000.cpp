#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n; 
	string str; 
	cin >> str;
	int k = n % 3; // ','이 출력될 위치 
	for (int i = 0; i < n; i++) { 
		if ((i % 3 == k) && i > 0) cout << ","; 
		cout << str[i];
	} 
	return 0; 
}

//int main() {
//	int num, nums;
//	string numss;
//	cin >> num >> nums;
//	while (nums / 1000) {
//		numss += "," + to_string(nums % 1000);
//		nums /= 1000;
//	}
//	numss = to_string(nums) + numss;
//	cout << numss;
//}