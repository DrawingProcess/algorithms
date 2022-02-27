#include <iostream>
using namespace std;

int main() {
	int temp;
	int count[5];
	int arr[30] = { 1,3,2,4,3,2,5,3,1,2,
					3,4,4,3,5,1,2,3,5,2,
					3,1,4,3,5,1,2,1,1,1 };
	for (int i = 0; i < 5; i++)
		count[i] = 0;
	for (int i = 0; i < 30; i++)
		count[arr[i] - 1]++;
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				cout << i + 1 << " ";
		}
	}
}

// BAEKJOON 10989
//#include <iostream>
//using namespace std;
//
//int main() {
//	int temp;
//	int count[10000];
//	for (int i = 0; i < 10000; i++)
//		count[i] = 0;
//	int num, n;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> n;
//		count[n - 1]++;
//	}
//	for (int i = 0; i < 10000; i++) {
//		if (count[i] != 0) {
//			for (int j = 0; j < count[i]; j++)
//				cout << i + 1 << "\n";
//		}
//	}
//}