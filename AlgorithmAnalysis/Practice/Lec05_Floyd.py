def allShortestPath(g,n):
    # node number는 1부터 n
    # 구현

def printMatrix(d):
    n = len(d[0])
    for i in range(0,n):
        for j in range(0,n):
            print(d[i][j],end=" ")
        print()

inf = 1000
g = [[0,1,inf, 1,5],
    [9,0,3,2,inf],
    [inf,inf,0,4,inf],
    [inf,inf,2,0,3],
    [3,inf,inf,inf,0]]

d, p = allShortestPath(g,5)
print()
printMatrix(d)
print()
printMatrix(p) 

# <<output>>
# 0 1 1000 1 5 
# 9 0 3 2 1000 
# 1000 1000 0 4 1000 
# 1000 1000 2 0 3 
# 3 1000 1000 1000 0 

# 0 1 3 1 4 
# 8 0 3 2 5 
# 10 11 0 4 7 
# 6 7 2 0 3 
# 3 4 6 4 0 

# 0 0 4 0 4 
# 5 0 0 0 4 
# 5 5 0 0 4 
# 5 5 0 0 0 
# 0 1 4 1 0 