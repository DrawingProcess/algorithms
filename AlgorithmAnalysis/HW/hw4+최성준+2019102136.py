import utility

def allShortestPath(g,n):
    # node number는 1부터 n
    D = g[:]
    P = [[0 for col in range(n)] for row in range(n)]
    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                if D[i][k]+D[k][j] < D[i][j]:
                    D[i][j] = D[i][k]+D[k][j]
                    P[i][j] = k+1
    return (D,P)

def printMatrix(d):
    n = len(d[0])
    for i in range(0,n):
        for j in range(0,n):
            print(d[i][j], end=" ")
        print()

inf=1000
g=[[0,1,inf, 1,5],
   [9,0,3,2,inf],
   [inf,inf,0,4,inf],
   [inf,inf,2,0,3],
   [3,inf,inf,inf,0]]

print("HW04_1 Floyd 알고리즘(p5_dp_bin_floyd_chainMatrix.mp4 p21)")
d, p = allShortestPath(g,5)
print()
printMatrix(d)
print()
printMatrix(p) 
print()

def path(p, q, r):
   if (p[q-1][r-1] !=0):
      path(p, q, p[q-1][r-1])
      print('v{}'.format(p[q-1][r-1]), end=" ")
      path(p, p[q-1][r-1], r)

print("HW04_2 최단경로 출력(p5_dp_bin_floyd_chainMatrix.mp4 p25)")                 
print()
utility.printMatrix(d)
print()
utility.printMatrix(p) 
print()

path(p, 5, 3)