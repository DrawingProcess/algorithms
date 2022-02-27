#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(const vector<int>& heights, int left, int right) {
    if (left == right) {
        return heights[left];
    }

    int mid = (left + right) / 2;
    int ret = max(solve(heights, left, mid), solve(heights, mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = min(heights[lo], heights[hi]);
    int area = height * 2;

    while (left < lo || hi < right) {

        if (hi < right && (lo == left || heights[lo - 1] < heights[hi + 1])) {
            hi += 1;
            height = min(height, heights[hi]);
        }
        else {
            lo -= 1;
            height = min(height, heights[lo]);
        }

        area = max(area, height * (hi - lo + 1));
    }

    return max(ret, area);
}

int solution(const int N, const vector<int>& heights) {
    return solve(heights, 0, N - 1);
}

int main() {
    // 무작정 풀기와 동일
    int C;
    cin >> C;

    if (!(0 < C && C <= 50)) {
        cout << "fail: C must be between 1 and 50" << endl;
        return 0;
    }

    for (int i = 0; i < C; i++) {
        int N;
        cin >> N;

        if (!(1 <= N && N <= 20000)) {
            cout << "fail: N must be between 1 and 20000" << endl;
            return 0;
        }

        vector<int> heights = vector<int>(N, 0);

        for (int j = 0; j < N; j++) {
            int h;
            cin >> h;

            if (!(0 <= h && h <= 10000)) {
                cout << "fail: h must be between 1 and 10000" << endl;
                return 0;
            }

            heights[j] = h;
        }

        int result = solution(N, heights);
        cout << result << endl;
    }

    return 0;
}

/*
//brute-force
int solution(const int N, const vector<int>& heights) {

    int result = 0;

    for (int i=0; i<N; i++) {
        int height = heights[i];
        int right = i + 1, left = i - 1;

        while (right < N && heights[right] >= height) {
            right += 1;
        }

        while (left >= 0 && heights[left] >= height){
            left -= 1;
        }

        int width = right - left - 1;
        result = max(result, height * width);
    }

    return result;
}
*/