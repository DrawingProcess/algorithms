#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};



bool BFS(int row, int col, vector<string> MAP)
{
    vector<vector<bool> > visit(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int> > Q;
    Q.push(make_pair(make_pair(row, col), 0));
    visit[row][col] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();

        if (Cnt == 2)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                if (visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == 'O')
                    {
                        visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                    }
                    else if (MAP[nx][ny] == 'P')
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int Find_Answer(vector<string> MAP)
{
    for (int row = 0; row < MAP.size(); row++)
    {
        for (int col = 0; col < MAP[row].size(); col++)
        {
            if (MAP[row][col] == 'P')
            {
                if (BFS(row, col, MAP) == false)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string> > places)
{
    vector<int> answer;
    for (int i = 0; i < places.size(); i++)
    {
        answer.push_back(Find_Answer(places[i]));
    }
    return answer;
}