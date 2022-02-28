#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > sizes)
{
    int answer = 0, row, col, rowM = 0, colM = 0;
    for (const auto &size : sizes)
    {
        if (size[0] > size[1])
        {
            row = size[0];
            col = size[1];
        }
        else
        {
            row = size[1];
            col = size[0];
        }
        rowM = rowM > row ? rowM : row;
        colM = colM > col ? colM : col;
    }
    answer = rowM * colM;
    return answer;
}

int main()
{
}