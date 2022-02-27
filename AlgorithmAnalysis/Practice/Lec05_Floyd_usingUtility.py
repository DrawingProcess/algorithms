from utility import *

def allShortestPath(g,n):
   D = g[:]
   P = [[0 for col in range(n)] for row in range(n)]
   for k in range(0,n):
      for i in range(0,n):
         for j in range(0,n):
            if D[i][k]+D[k][j] < D[i][j]:
               D[i][j] = D[i][k]+D[k][j]
               P[i][j] = k+1
   return (D,P)

def path(p, q, r):
   if (p[q-1][r-1] !=0):
      path(p, q, p[q-1][r-1])
      print('v{}'.format(p[q-1][r-1]), end=" ")
      path(p, p[q-1][r-1], r)

inf=1000
g=[[0,1,inf, 1,5],
   [9,0,3,2,inf],
   [inf,inf,0,4,inf],
   [inf,inf,2,0,3],
   [3,inf,inf,inf,0]]
d, p = allShortestPath(g,5)
print()
printMatrix(d)
print()
printMatrix(p) 
                 
path(p, 5, 3)

# <<output>>

#    0    1 1000    1    5 
#    9    0    3    2 1000 
# 1000 1000    0    4 1000 
# 1000 1000    2    0    3 
#    3 1000 1000 1000    0 

#    0    1    3    1    4 
#    8    0    3    2    5 
#   10   11    0    4    7 
#    6    7    2    0    3 
#    3    4    6    4    0 

#    0    0    4    0    4 
#    5    0    0    0    4 
#    5    5    0    0    4 
#    5    5    0    0    0 
#    0    1    4    1    0 
# v1 v4 
