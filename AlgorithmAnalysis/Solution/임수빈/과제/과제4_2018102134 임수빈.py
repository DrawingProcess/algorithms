import time
#알고리즘 분석 - 과제4
#소프트웨어융합학과
#2018102134 임수빈

def bin(n,k):
    if k==0 or n ==k:
        return 1
    else:
        return bin(n-1,k-1) + bin(n-1,k)


def bin2(n,k):
    B = [[0 for col in range(k+1)] for row in range(n+1)]
    for i in range(n+1):
        for j in range(min(i,k)+1):
            if j == 0 or j ==i:
                B[i][j] = 1

            else:
                B[i][j] = B[i-1][j-1] + B[i-1][j]
    return B[n][k]
 
 

print(bin(10,5), bin2(10,5))

def printMatrix(d):
    m = len(d)
    n=len(d[0])
    
    for i in range(0,m):
        for j in range(0,n):
            print("%4d" % d[i][j],end=" ")
        print()


def copyM(g):
    l = []
    for row in g:
        l.append(row.copy())
    return l

def allShortestPath(g,n):
    D = copyM(g)
    P = [[0 for col in range(n)] for row in range(n)]
    
    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                if D[i][k]+D[k][j] < D[i][j]:
                    P[i][j] = k+1
                    D[i][j] = D[i][k]+D[k][j]
    return (D,P)


def path2(p, q, r):
    if (p[q-1][r-1] !=0):
        path2(p,q, p[q-1][r-1])
        print("v"+str(p[q-1][r-1]),end=" ")
        path2(p,p[q-1][r-1],r)


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
                 
path2(p, 5, 3)


