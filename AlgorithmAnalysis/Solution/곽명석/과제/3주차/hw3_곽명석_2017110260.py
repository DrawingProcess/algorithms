from numpy import *

#page 07 빠른정렬

def quickSort(s,low,high):
    if(high>low):
        pivotpoint = partition(s,low,high)
        quickSort(s,low,pivotpoint-1)
        quickSort(s,pivotpoint+1,high)

def partition(s,low,high):
    pivotitem = s[low]
    j=low
    for i in range(low+1,high+1):
        if(s[i]<pivotitem):
            j+=1
            temp = s[i]             # exchange s[i] and s[j]
            s[i] = s[j]
            s[j] = temp

    pivotpoint = j
    temp = s[low]           #exchange s[low] and s[pivotpoint]
    s[low] = s[pivotpoint]
    s[pivotpoint] = temp


    return pivotpoint


s=[3,5,2,9,10,14,4,8]
quickSort(s,0,7)
#print(s)


#page 21 쉬트라센
def strassen(n,A,B,C):
    threshold =2
    index = int(n/2)
    # A 행렬 4분할
    A11 = array([[A[rows][cols] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    A12 = array([[A[rows][cols+index] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    A21 = array([[A[rows+index][cols] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    A22 = array([[A[rows+index][cols+index] for cols in range(int(n/2))]  for rows in range(int(n/2))])

    # B 행렬 4분할
    B11 = array([[B[rows][cols] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    B12 = array([[B[rows][cols+index] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    B21 = array([[B[rows+index][cols] for cols in range(int(n/2))]  for rows in range(int(n/2))])
    B22 = array([[B[rows+index][cols+index] for cols in range(int(n/2))]  for rows in range(int(n/2))])


    if(n<=threshold):
        C = array(A) @ array(B)
    else:
        M1 = M2 =M3 =M4 =M5 =M6 =M7 = array([[0 for i in range(index) ]for j in range(index)])      # M 행렬 초기화.
        M1 = strassen(int(n/2), (A11 + A22), (B11 + B22),M1)
        M2 = strassen(int(n/2), (A21 + A22), B11,M2)
        M3 = strassen(int(n/2), A11, (B12 - B22),M3)
        M4 = strassen(int(n/2), A22, (B21 - B11),M4)
        M5 = strassen(int(n/2), (A11 + A12), B22,M5)
        M6 = strassen(int(n/2), (A21-A11), (B11 +  B12),M6)
        M7 = strassen(int(n/2), (A12 -A22), (B21 + B22),M7)
        C = vstack([ hstack([M1+M4-M5+M7, M3 +M5]), hstack([M2+M4, M1 + M3 - M2 + M6]) ])
    return C

n =  4
A = [ [1,2,0,2], [3,1,0,0], [0,1,1,2], [2,0,2,0] ]
B = [ [0,3,0,2], [1,1,4,0], [1,1,0,2], [0,5,2,0] ]
C = array(A) @ array(B)
print(C)
D = [[0 for cols in range(n)] for rows in range(n)]
D = strassen(n,A,B,D)
print(D)
