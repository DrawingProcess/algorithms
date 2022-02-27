#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!check[next]) {
			dfs(next, graph, check);
		}
	}
}
void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < graph[tmp].size(); i++) {
			if (!check[graph[tmp][i]]) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}