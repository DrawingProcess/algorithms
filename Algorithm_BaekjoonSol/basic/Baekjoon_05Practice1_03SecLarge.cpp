#include <iostream>
using namespace std;
void swap(int& A, int& B) {
	int temp = A;
	A = B;
	B = temp;
}
int main() {
	const int max = 100, min = 1;
	int A[3];
	for (int i = 0; i < 3; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
		}
	}
	cout << A[1];
	//const int max = 100, min = 1;
	//int A[3], numL = min, numS = max;
	//for (int i = 0; i < 3; i++) {
	//	cin >> A[i];
	//	A[i] >= numL ? numL = A[i] : A[i];
	//	A[i] <= numS ? numS = A[i] : A[i];
	//}
	//for (int i = 0; i < 3; i++) {
	//	if (A[i] != numL && A[i] != numS && min <= A[i] && max >= A[i])
	//		cout << A[i];

	//}
}
/* hardcording solution
#include <iostream>
using namespace std;
int main(){
    int a, b, c, mid;
    cin>>a>>b>>c;

    if(a > b){
        if(c > a)
        {
            cout<<a;
            return 0;
        }
        else if(c > b)
        {
            cout<<c;
            return 0;
        }
        else
        {
            cout<<b;
            return 0;
        }
        if(b > c)
        {
            cout<<b;
            return 0;
        }
        else if(a > c)
        {
            cout<<c;
            return 0;
        }
        else{
            cout<<a;
            return 0;
        }
    }
    else{
        if(c > b)
        {
            cout<<b;
            return 0;
        }
        else if( c > a)
        {
            cout<<c;
            return 0;
        }
        else{
            cout<<a;
            return 0;
        }
        if(a>c)
        {
            cout<<a;
            return 0;
        }
        else if(b>c)
        {
            cout<<c;
            return 0;
        }
        else{
            cout<<b;
            return 0;
        }
    }
}

*/