#include <iostream>
#include <cstring> // for memset
using namespace std;
char *mysubstr(char *str, int start, int count) {
	char* chr = (char*)malloc(count);
	memset(chr, 0, count+1);
	int i = 0;
	while (count > i) {
		chr[i] = str[start + i];
		i++;
	}
	return chr;
}
int main() {
	char str[101];
	cin >> str;
	int start, count;
	cin >> start >> count;
	cout << mysubstr(str, start, count);
}