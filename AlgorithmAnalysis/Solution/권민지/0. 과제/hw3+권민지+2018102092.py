# @@@ author : 2018102092 minji kwon
# @@@ 2020 analysis of algorithms assignment 03

### 1. slide 07 - quick sort program ###
def partition(s, low, high):
    # 구현
    i = (low - 1)
    temp = s[high]

    for j in range(low, high):

        if s[j] <= temp:
            i = i + 1
            s[i], s[j] = s[j], s[i]

    s[i + 1], s[high] = s[high], s[i + 1]
    # 구현 종료

    return (i + 1)


def quickSort(s, low, high):
    # 구현
    if len(s) == 1:
        return s
    if low < high:
        tmp = partition(s, low, high)

        quickSort(s, low, tmp - 1)
        quickSort(s, tmp + 1, high)
    # 구현 종료

s=[3,5,2,9,10,14,4,8]
quickSort(s,0,7)
print("Quick sort")
print(s, "\n")


### 2. Slide 21 - Strassen algorithm ###
from numpy import *

def strassen(n, A, B, C):
    threshold = 2
    A11 = array([[A[rows][cols] for cols in range(int(n/2))]for rows in range(int(n/2))])
    
    # 구현
    A12 = array([[A[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])
    A21 = array([[A[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])
    A22 = array([[A[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])

    num = int(len(A[0])/2)
    for i in range(0, num):
        for j in range(0, num):
            A11[i][j] = A[i][j]  # 좌 상단행렬
            A12[i][j] = A[i][j + num]  # 우 상단행렬
            A21[i][j] = A[i + num][j]  # 좌 하단행렬
            A22[i][j] = A[i + num][j + num]  # 우 하단행렬

    B11 = array([[B[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])
    B12 = array([[B[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])
    B21 = array([[B[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])
    B22 = array([[B[rows][cols] for cols in range(int(n / 2))] for rows in range(int(n / 2))])

    num2 = int(len(B[0]) / 2)
    for i in range(0, num2):
        for j in range(0, num2):
            B11[i][j] = B[i][j]  # 좌 상단행렬
            B12[i][j] = B[i][j + num2]  # 우 상단행렬
            B21[i][j] = B[i + num2][j]  # 좌 하단행렬
            B22[i][j] = B[i + num2][j + num2]  # 우 하단행렬

    #print("test")
    #print(A11, A12, A21, A22, B11, B12, B21, B22)
    # 구현 종료

    if(n <= threshold):
        C = array(A) @ array(B)
    else:
        M1 = M2 = M3 = M4 = M5 = M6 = M7 = array([])
        M1 = strassen(int(n / 2), (A11 + A22), (B11 + B22), M1)

        # 구현
        M2 = strassen(int(n / 2), (A21 + A22), B11, M2)
        M3 = strassen(int(n / 2), A11, (B12 - B22), M3) #
        M4 = strassen(int(n / 2), A22, (B21 - B11), M4) #
        M5 = strassen(int(n / 2), (A11 + A12), B22, M5)
        M6 = strassen(int(n / 2), (A21 - A11), (B11 + B12), M6) #
        M7 = strassen(int(n / 2), (A12 - A22), (B21 + B22), M7) #

        ###
        #print("etest")
        #print(M1, M2, M3, M4, M5, M6, M7)
        # 구현 종료

        C =  vstack([ hstack([M1+M4 -M5 + M7, M3 + M5]), hstack([M2 + M4, M1 + M3 - M2 + M6]) ])

    return C

n = 4
A=[ [1,2,0,2], [3,1,0,0], [0,1,1,2],[2,0,2,0]]
B=[ [0,3,0,2], [1,1,4,0], [1,1,0,2],[0,5,2,0]]
C = array(A)@array(B)
print("array(A) @ array(B)")
print(C)

D = [[0 for cols in range(n)]for rows in range(n)]
D=strassen(n, A, B, D)
print("Strassen algorithm")
print(D)


