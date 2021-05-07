# (1) 6쪽: [실습프로그램] 그래프의 깊이우선검색 알고리즘을 다음 사항을 반영하여
# python으로 완성하라. 출력은 (방문순서, 방문노드번호) 되도록 수정한다. 예를 들어, 주
# 어진 그래프에 대해 다음과 같이 출력되어야 한다. 첫 번째 방문순서는 1로 한다.

print("---------------------------------------------------------------")
print("HW06_1 Depth First Search(p10_treeTraversal_n_Queens.pptx p6)\n")
# import utility
e = {0:[1,2,3], 1:[2,5], 2:[3,4,5,6], 3:[4,6], 4:[6,7]}
n = 8
a = [[0 for j in range(0,n)] for i in range(0,n)]
for i in range(0,n-1):
    for j in range(i+1,n):
        if i in e:
           if j in e[i]:
              a[i][j] = 1
              a[j][i] = 1
# utility.printMatrix(a)

visited = n*[0]
def DFS(a, v):
    # 깊이우선검색 구현
    visited[v] = 1
    cnt = 0
    for i in range(len(visited)): # count: cnt
        if (visited[i]):
            cnt += 1 
    print(cnt, v)
    cnt += 1
    for i in range(n):
        if visited[i] == 0 and a[v][i] == 1:
            DFS(a, i)
DFS(a, 0)
# (2) 18쪽: [실습프로그램] n-Queens 문제 해결 알고리즘을 python으로 완성하여 n=7
# 문제의 해의 총개수 및 세 번째 해를 출력하라.
print("---------------------------------------------------------------")
print("HW06_2 n-Queens 알고리즘(p10_treeTraversal_n_Queens.pptx p18)\n")
def promising(i,col):
    k = 0
    switch = True
    while(k < i and switch):
        if col[i] == col[k] or abs(col[i] - col[k]) == i-k:
            switch = False
        k += 1
    return switch
def queens(n,i,col):
    global cnt
    if promising(i,col):
        if i+1 == n:
            cnt += 1
            if (cnt == 3): # 3번째 해 도출
                print(col)
        else:
            for j in range(0,n):
                col[i+1] = j
                queens(n,i+1,col)

n = 7
col=n*[0]
cnt = 0
queens(n,-1,col)
print(cnt) # global cnt
print("---------------------------------------------------------------")
