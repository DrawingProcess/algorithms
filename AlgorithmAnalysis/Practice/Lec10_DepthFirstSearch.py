import utility
e = {0:[1,2,3], 1:[2,5], 2:[3,4,5,6], 3:[4,6], 4:[6,7]}
n = 8
a = [[0 for j in range(0,n)] for i in range(0,n)]
for i in range(0,n-1):
    for j in range(i+1,n):
        if i in e:
           if j in e[i]:
              a[i][j] = 1
              a[j][i] = 1
utility.printMatrix(a)

visited = n*[0]

def DFS(a, v):
    # 깊이우선검색 구현
    visited[v] = 1
    print(v)
    for i in range(n):
        if visited[i] == 0 and a[v][i] == 1:
            DFS(a, i)

DFS(a, 0)