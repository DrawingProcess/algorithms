#include <iostream>
using namespace std;
int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	w -= x; h -= y;
	x = x >= w ? w : x;
	y = y >= h ? h : y;
	cout << (x >= y ? y : x);
}

//// my sol
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//int main() {
//	int x, y, min = 1000000, num;
//	double w, h;
//	vector<int> dis, x_d, y_d;
//	cin >> x >> y >> w >> h;
//	x_d.push_back(x - w);
//	x_d.push_back(x - w);
//	x_d.push_back(0);
//	x_d.push_back(0);
//	y_d.push_back(y - h);
//	y_d.push_back(0);
//	y_d.push_back(y - h);
//	y_d.push_back(0);
//
//	dis.push_back(sqrt(pow(x - w, 2) + pow(y - h, 2)));
//	dis.push_back(sqrt(pow(x - w, 2) + pow(y - 0, 2)));
//	dis.push_back(sqrt(pow(x - 0, 2) + pow(y - h, 2)));
//	dis.push_back(sqrt(pow(x - 0, 2) + pow(y - 0, 2)));
//	for (int i = 0; i < 4; i++)
//		if (min > dis[i]) {
//			min = dis[i];
//			num = i;
//		}
//	for (int i = num+1; i < 4; i++)
//		if (dis[num] == dis[i] && num != i) {
//			if (x_d[num] == x_d[i]) {
//				min = sqrt(pow(dis[num], 2) - pow(h / 2, 2));
//			}
//			else if (y_d[num] == y_d[i]) {
//				min = sqrt(pow(dis[num], 2) - pow(w / 2, 2));
//			}
//		}
//	cout << min;
//}