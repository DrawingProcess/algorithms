# (1) 7쪽: [실습프로그램] 그래프의 너비우선검색 알고리즘을 python으로 완성하라.
# utility class 구현 시작
class util:     # Utility class
    def __init__(self):
        pass

    def printMatrix(self, d):
        m = len(d)
        n = len(d[0])

        for i in range(0, m):
            for j in range(0, n):
                print("%4d" % d[i][j], end=" ")
            print()

utility = util()    # class constructor

# utility class 구현 종료

e = {0: [1, 2, 3], 1: [2, 5], 2: [3, 4, 5, 6], 3: [4, 6], 4: [6, 7]}
n = 8
a = [[0 for j in range(0, n)] for i in range(0, n)]
for i in range(0, n - 1):
    for j in range(i + 1, n):
        if i in e:
            if j in e[i]:
                a[i][j] = 1
                a[j][i] = 1
utility.printMatrix(a)

# 구현 시작
import collections as c

def BFS(a, v):
    queue = c.deque()
    queue.append(v)
    visited = set()

    while queue:
        x = queue.popleft()

        if x in visited:
            continue

        print(x, end="\n")
        visited.add(x)

        if a.get(x):
            [queue.append(i) for i in sorted(a[x])]

BFS(e, 0)
print()

#구현 종료

# (2) 17쪽: [실습프로그램] n-Queens 문제 해결 알고리즘을 python으로 완성하여 n=7 문제의 해의 개수를 출력하라.
#구현 시작
def queens(sol, N):
    global count

    if len(sol) == N:
        count += 1
        print(sol)
        return 0
    candidate = list(range(N))

    for i in range(len(sol)):
        if sol[i] in candidate:
            candidate.remove(sol[i])
        dist = len(sol) - i

        if sol[i] + dist in candidate:
            candidate.remove(sol[i] + dist)

        if sol[i] - dist in candidate:
            candidate.remove(sol[i] - dist)

    if candidate != []:
        for i in candidate:
            sol.append(i)
            queens(sol, N)
            sol.pop()
    else:
        return 0

count = 0
n = 7
for i in range(n):
    queens([i], n)
#구현 종료