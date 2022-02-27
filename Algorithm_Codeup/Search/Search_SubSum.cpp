#include <iostream>
#include <vector>
using namespace std;
bool promising(int i) {
    return (weight + total >= W) && weight + w[i + 1] <= W);
}
void sum_of_subsets(int i, int weight, int total) {
    if (promising(i)) {
        if (weight == W)
            cout << include[1] through include[i];
        else {
            include[i + 1] = "yes";
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
            include[i + 1] = "no";
            sum_of_subsets(i + 1, weight, total - w[i + 1]);
        }

    }
}
int main() {
	vector<int> sum;
	int n, s, num;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum[i]
	}
}