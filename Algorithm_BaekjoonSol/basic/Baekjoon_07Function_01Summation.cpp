#include <vector>
using namespace std;

long long sum(vector<int>& a) {
	long long sum = 0;
	for (unsigned i = 0; i < a.size(); i++)
		sum += a[i];
	//for (vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
	//	sum += *iter;
	return sum;
}
