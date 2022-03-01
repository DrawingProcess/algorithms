#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Max_Size;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visit[100][100];

int BFS(int row, int col, int m, int n, vector<vector<int> > picture)
{
    int color = picture[row][col];
    int size = 1;
    queue<pair<int, int> > Q;
    Q.push(make_pair(row, col));
    visit[row][col] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n)
            {
                if (picture[nx][ny] == color && visit[nx][ny] == false)
                {
                    visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                    size++;
                }
            }
        }
    }
    return size;
}

vector<int> solution(int m, int n, vector<vector<int> > picture)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (picture[row][col] != 0 && visit[row][col] == false)
            {
                int size = BFS(row, col, m, n, picture);
                if (size > max_size_of_one_area) 
                {
                    max_size_of_one_area = size;
                }
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}