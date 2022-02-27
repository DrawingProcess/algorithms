from numpy import *
def strassen (n, A, B, C):
    threshold = 2
    A11 = array([[A[rows][cols] for cols in range(int(n/2))] for rows in range(int(n/2))])
        # 구현

#    print(A11, A12, A21, A22, B11, B12, B21, B22)
    if (n <= threshold):
        C = array(A) @ array(B)
    else:
        M1 = M2 = M3 = M4 = M5 = M6 = M7 = array([])
        M1=strassen(int(n/2), (A11 + A22) , (B11 + B22), M1)
        # 구현 

        C =  vstack([ hstack([M1+M4 -M5 + M7, M3 + M5]), hstack([M2 + M4, M1 + M3 - M2 + M6]) ])
    return C
n = 4
#A = [[1 for cols in range(n)]for rows in range(n)]
#B = [[2 for cols in range(n)]for rows in range(n)]
A=[ [1,2,0,2], [3,1,0,0], [0,1,1,2],[2,0,2,0]]
B=[ [0,3,0,2], [1,1,4,0], [1,1,0,2],[0,5,2,0]]
C = array(A)@array(B)
D = [[0 for cols in range(n)]for rows in range(n)]
print(C)
D=strassen(n, A, B, D)
print(D)
