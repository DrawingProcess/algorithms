#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mini;
void comp(int val) {
    mini = min(mini, val);
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matric;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            answer.push_back((i * columns) + (j + 1));
        }
        matric.push_back(answer);
        answer.clear();
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < queries.size(); i++) {
        mini = rows * columns;
        y1 = queries[i][0] - 1, x1 = queries[i][1] - 1;
        y2 = queries[i][2] - 1, x2 = queries[i][3] - 1;
        int temp = matric[y1][x1];
        comp(temp);
        for(int i=y1; i<y2; i++){
            matric[i][x1]=matric[i+1][x1];
            comp(matric[i+1][x1]);
        }
        for(int j=x1; j<x2; j++){
            matric[y2][j] = matric[y2][j+1];
            comp(matric[y2][j+1]);
        }
        for(int i=y2; i>y1; i--){
            matric[i][x2] = matric[i-1][x2];
            comp(matric[i-1][x2]);
        }
        for(int j=x2; j>x1+1; j--){
            matric[y1][j] = matric[y1][j-1];
            comp(matric[y1][j-1]);
        }
        matric[y1][x1 + 1] = temp;
        answer.push_back(mini);
        //for (int j = 0; j < rows; j++) {
        //    for (int k = 0; k < columns; k++) {
        //        cout << matric[j][k] << " ";
        //    }
        //    cout << "\n";
        //}
    }
    return answer;
}
int main() {
    int rows = 6, columns = 6;
    vector<vector<int>> queries = { {2,2,5,4}, {3,3,6,6}, {5,1,6,3} };
    //result: [8, 10, 25]
    vector<int> result = solution(rows, columns, queries);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}