#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string> > places)
{
    vector<vector<bool> > able(5);
    for (int i = 0; i < 5; i++){
        able[i].resize(5);
    }
    vector<int> answer;
    for (int r = 0; r < places.size(); r++)
    {
        for (int c = 0; c < places[0].size(); c++)
        {
            if (places[r][c] == 'P')
            {
                if (able[r][c] == 1)
                {

                }
                else
                {
                    answer.push_back(0);
                    break;
                }
            }
            else if (places[r][c] == 'X')
            {
                able[r][c] = 0;
                if (r != 0) able[r - 1][c] = 1;
                if (r != 4) able[r + 1][c] = 1;
                if (c != 0) able[r][c - 1] = 1;
                if (c != 4) able[r][c + 1] = 1;
            }
        }
    }
    return answer;
}