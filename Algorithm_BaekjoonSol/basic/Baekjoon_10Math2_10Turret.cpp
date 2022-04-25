#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, x1, y1, r1, x2, y2, r2, ret;
	double d;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        int minus = abs(r1 - r2);
        int plus = r1 + r2;

        if (d == 0.0) {
            if (r1 == r2)
                ret = -1;
            else
                ret = 0;
        }
        else {
            if (minus < d && plus > d)
                ret = 2;
            else if (plus == d || minus == d)
                ret = 1;
            else
                ret = 0;
        }
        cout << ret << endl;
    }
}