import Lec05_Utility as utility

def order(p, i, j):
    if (i == j):
        print("A", i)
    else:
        k = p[i][j]
        print("(")
        order(i, k)
        order(k+1, j)
        print(")")
         
d = [5,2,3,4,6,7,8]
n = len(d)-1

m=[[0 for j in range(1,n+2)] for i in range(1,n+2)]
p=[[0 for j in range(1,n+2)] for i in range(1,n+2)]

def minmult (n, d, P):
    M = [[0 for i in range(n+1)] for j in range(n+1)]
    for i in range(1, n+1):
        M[i][i] = 0
    for diag in range(1, n):
        for i in range(1, n-diag+1):
            j = i + diag
            M[i][j] = min(M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j])
            P[i][j] = k # 최소치를 주는 k의 값
    return M[1][n]


utility.printMatrix(m)
print()
utility.printMatrix(p)
order(p,1,6)

# << output >>
#    0    0    0    0    0    0    0 
#    0    0   30   64  132  226  348 
#    0    0    0   24   72  156  268 
#    0    0    0    0   72  198  366 
#    0    0    0    0    0  168  392 
#    0    0    0    0    0    0  336 
#    0    0    0    0    0    0    0 

#    0    0    0    0    0    0    0 
#    0    0    1    1    1    1    1 
#    0    0    0    2    3    4    5 
#    0    0    0    0    3    4    5 
#    0    0    0    0    0    4    5 
#    0    0    0    0    0    0    5 
#    0    0    0    0    0    0    0 
# (A 1((((A 2A 3)A 4)A 5)A 6))
